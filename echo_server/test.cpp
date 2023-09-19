#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/event.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <map>
#include <vector>

const int MAX_EVENTS = 10;
const int BUFFER_SIZE = 1024;

void exit_with_perror(const std::string& msg) {
	std::cerr << msg << "\n";
	exit(EXIT_FAILURE);
}

void change_events(std::vector<struct kevent>& change_list, uintptr_t ident, short filter, u_short flags, u_int fflags,
				   int64_t data, void* udata) {
	struct kevent temp_event;

	EV_SET(&temp_event, ident, filter, flags, fflags, data, udata);
	change_list.push_back(temp_event);
}

void disconnect_client(int client_fd, std::map<int, std::string>& clients) {
	std::cout << "client disconnect: " << client_fd << "\n";
	close(client_fd);
	clients.erase(client_fd);
}

int main(void) {
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
		exit_with_perror("socket failed: " + std::string(strerror(errno)));

	int opt = 1;
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
		close(server_fd);
		exit_with_perror("setsockopt failed: " + std::string(strerror(errno)));
	}

	sockaddr_in server_addr;
	std::memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(8080);

	if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		close(server_fd);
		exit_with_perror("bind failed: " + std::string(strerror(errno)));
	}

	if (listen(server_fd, 5) < 0) {
		close(server_fd);
		exit_with_perror("listen failed: " + std::string(strerror(errno)));
	}

	int kq = kqueue();
	if (kq < 0) {
		close(server_fd);
		exit_with_perror("kqueue failed: " + std::string(strerror(errno)));
	}

	std::map<int, std::string> clients;
	std::vector<struct kevent> change_list;
	struct kevent event_list[8];

	change_events(change_list, server_fd, EVFILT_READ, EV_ADD, 0, 0, NULL);

	int new_events;
	struct kevent* curr_event;
	while (true) {
		new_events = kevent(kq, &change_list[0], change_list.size(), event_list, 8, NULL);
		if (new_events == -1)
			exit_with_perror("kevent() failed: " + std::string(strerror(errno)));

		change_list.clear();
		printf("hi\n");
		for (int i = 0; i < new_events; ++i) {
			curr_event = &event_list[i];

			if (curr_event->flags & EV_ERROR) {
				if (static_cast<int>(curr_event->ident) == server_fd)
					exit_with_perror("server socket error\n");
				else {
					std::cerr << "client socket error\n";
					disconnect_client(curr_event->ident, clients);
				}
			} else if (curr_event->flags & EV_EOF) {
				close(curr_event->ident);
			} else if (curr_event->filter == EVFILT_READ) {
				if (static_cast<int>(curr_event->ident) == server_fd) {
					int client_fd = accept(server_fd, NULL, NULL);
					if (client_fd == -1)
						exit_with_perror("accept() error\n");
					std::cout << "accept new client: " << client_fd << std::endl;
					fcntl(client_fd, F_SETFL, O_NONBLOCK | O_CLOEXEC);

					change_events(change_list, client_fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
					clients[client_fd] = "";
				} else if (clients.find(curr_event->ident) != clients.end()) {
					char buf[BUFFER_SIZE];
					int n = read(curr_event->ident, buf, sizeof(buf));

					if (n <= 0) {
						disconnect_client(curr_event->ident, clients);
					} else {
						buf[n] = '\0';
						clients[curr_event->ident] += buf;
						change_events(change_list, curr_event->ident, EVFILT_WRITE, EV_ADD, 0, 0, NULL);
					}
				}
			} else if (curr_event->filter == EVFILT_WRITE) {
				std::map<int, std::string>::iterator it = clients.find(curr_event->ident);
				if (it != clients.end()) {
					clients[curr_event->ident] += "_server";
					int n =
						write(curr_event->ident, clients[curr_event->ident].c_str(), clients[curr_event->ident].size());
					if (n < 0) {
						std::cerr << "client write error\n";
						disconnect_client(curr_event->ident, clients);
					} else {
						clients[curr_event->ident].erase(0, n);
						if (clients[curr_event->ident].empty()) {
							change_events(change_list, curr_event->ident, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
						}
					}
				}
			}
		}
	}
	return (0);
}