#include <cerrno>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/event.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

const int MAX_EVENTS = 10;
const int BUFFER_SIZE = 1024;

struct ClientData {
	int fd;
	std::string buffer;
};

int main() {
	int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_fd < 0) {
		std::cerr << "socket failed: " << strerror(errno) << "\n";
		return -1;
	}

	int opt = 1;
	if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
		std::cerr << "setsockopt failed: " << strerror(errno) << "\n";
		close(listen_fd);
		return -1;
	}

	sockaddr_in server_addr;
	std::memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(8080);

	if (bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		std::cerr << "bind failed: " << strerror(errno) << "\n";
		close(listen_fd);
		return -1;
	}

	if (listen(listen_fd, 5) < 0) {
		std::cerr << "listen failed: " << strerror(errno) << "\n";
		close(listen_fd);
		return -1;
	}

	int kq = kqueue();
	if (kq < 0) {
		std::cerr << "kqueue failed: " << strerror(errno) << "\n";
		close(listen_fd);
		return -1;
	}

	struct kevent evSet;

	if (kevent(kq, &evSet, 1, NULL, 0, NULL) < 0) {
		std::cerr << "kevent add failed: " << strerror(errno) << "\n";
		close(listen_fd);
		close(kq);
		return -1;
	}

	struct kevent evList[MAX_EVENTS];
	while (true) {
		int n = kevent(kq, NULL, 0, evList, MAX_EVENTS, NULL);
		if (n < 0) {
			std::cerr << "kevent get failed: " << strerror(errno) << "\n";
			break;
		}

		for (int i = 0; i < n; ++i) {
			if (evList[i].ident == listen_fd) {
				sockaddr_in client_addr;
				socklen_t client_len = sizeof(client_addr);
				int client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_len);
				if (client_fd < 0) {
					std::cerr << "accept failed: " << strerror(errno) << "\n";
					continue;
				}

				ClientData* client_data = new ClientData;
				client_data->fd = client_fd;

				EV_SET(&evSet, client_fd, EVFILT_READ, EV_ADD, 0, 0, client_data);
				if (kevent(kq, &evSet, 1, NULL, 0, NULL) < 0) {
					std::cerr << "kevent add client failed: " << strerror(errno) << "\n";
					close(client_fd);
					delete client_data;
				}
			} else if (evList[i].flags & EV_EOF) {
				close(evList[i].ident);
				delete reinterpret_cast<ClientData*>(evList[i].udata);
			} else if (evList[i].filter == EVFILT_READ) {
				ClientData* client_data = reinterpret_cast<ClientData*>(evList[i].udata);
				char buffer[BUFFER_SIZE];
				int len = read(client_data->fd, buffer, BUFFER_SIZE);
				if (len > 0) {
					client_data->buffer.append("server_");
					client_data->buffer.append(buffer, len);

					EV_SET(&evSet, client_data->fd, EVFILT_WRITE, EV_ADD, 0, 0, client_data);
					if (kevent(kq, &evSet, 1, NULL, 0, NULL) < 0) {
						std::cerr << "kevent add write event failed: " << strerror(errno) << "\n";
					}
				} else if (len < 0) {
					std::cerr << "read failed: " << strerror(errno) << "\n";
				}
			} else if (evList[i].filter == EVFILT_WRITE) {
				ClientData* client_data = reinterpret_cast<ClientData*>(evList[i].udata);

				int len = write(client_data->fd, client_data->buffer.c_str(), client_data->buffer.size());
				if (len > 0) {
					client_data->buffer.erase(0, len);
					if (client_data->buffer.empty()) {
						EV_SET(&evSet, client_data->fd, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
						kevent(kq, &evSet, 1, NULL, 0, NULL);
					}
				} else if (len < 0) {
					std::cerr << "write failed: " << strerror(errno) << "\n";
				}
			}
		}
	}

	close(listen_fd);
	close(kq);
	return 0;
}
