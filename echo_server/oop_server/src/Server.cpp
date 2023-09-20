#include "Server.hpp"

Server::Server(int port) : _port(port) {
	std::cout << "Server create\n";
	this->init_server();
	std::cout << this->_port << std::endl;
}

void Server::init_server() {
	std::cout << "init server\n";
	this->server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->server_fd < 0)
		throw std::runtime_error("socket() failed\n");

	try {
		int opt = 1;
		if (setsockopt(this->server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
			throw std::runtime_error("setsockopt() failed\n");
		}

		std::memset(&server_addr, 0, sizeof(server_addr));
		server_addr.sin_family = AF_INET;
		server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
		server_addr.sin_port = htons(this->_port);

		if (bind(this->server_fd, (struct sockaddr*)&this->server_addr, sizeof(this->server_addr)) < 0) {
			throw std::runtime_error("bind() error\n");
		}

		if (listen(this->server_fd, 5) < 0) {
			throw std::runtime_error("listen() error\n");
		}

		this->kq = kqueue();
		if (kq < 0) {
			throw std::runtime_error("kqueue() error\n");
		}
		change_events(this->server_fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
	} catch (std::exception& e) {
		close(this->server_fd);
		throw;
	}
}

void Server::accept_client() {
	std::cout << "accept\n";
	sockaddr_in client_addr;
	socklen_t client_addr_length = sizeof(client_addr);

	int client_fd = accept(this->server_fd, (struct sockaddr*)&client_addr, &client_addr_length);
	if (client_fd < 0)
		throw std::runtime_error("accept error\n");

	try {
		this->clients[client_fd] = new ClientHandler(client_fd, client_addr);
	} catch (std::exception& e) {
		close(client_fd);
		throw std::runtime_error("Memory allocation error\n");
	}

	fcntl(client_fd, F_SETFL, O_NONBLOCK);
	change_events(client_fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
}

void Server::handle_events() {
	std::cout << "handle_event\n";
	int new_events = kevent(this->kq, &this->change_list[0], this->change_list.size(), this->event_list, 10, NULL);
	if (new_events == -1)
		throw std::runtime_error("kevent error\n");

	this->change_list.clear();

	for (int i = 0; i < new_events; ++i) {
		struct kevent* curr_event = &event_list[i];

		if (curr_event->flags & EV_ERROR) {
			if (static_cast<int>(curr_event->ident) == server_fd)
				throw std::runtime_error("serve socket error\n");
			else {
				disconnect_client(curr_event->ident);
				throw std::runtime_error("client socket error\n");
			}
		} else if (curr_event->flags & EV_EOF) {
			close(curr_event->ident);
		} else if (curr_event->filter == EVFILT_READ) {
			if (static_cast<int>(curr_event->ident) == server_fd) {
				this->accept_client();
			} else if (this->clients.find(curr_event->ident) != clients.end()) {
				if (clients[curr_event->ident]->read_data() > 0)
					change_events(curr_event->ident, EVFILT_WRITE, EV_ADD, 0, 0, NULL);
				else
					disconnect_client(curr_event->ident);
			}
		} else if (curr_event->filter == EVFILT_WRITE) {
			std::cout << "write\n";
			std::map<int, ClientHandler*>::iterator it = clients.find(curr_event->ident);
			if (it != clients.end()) {
				int n;
				if ((n = clients[curr_event->ident]->write_data()) >= 0) {
					clients[curr_event->ident]->erase_buffer(n);
					if (clients[curr_event->ident]->is_empty_buffer())
						change_events(curr_event->ident, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
				}
			}
		}
	}
}

void Server::change_events(uintptr_t ident, short filter, u_short flags, u_int fflags, int64_t data, void* udata) {
	struct kevent temp_event;

	EV_SET(&temp_event, ident, filter, flags, fflags, data, udata);
	this->change_list.push_back(temp_event);
}

void Server::disconnect_client(int client_fd) {
	std::cout << "client disconnect: " << client_fd << "\n";
	close(client_fd);
	this->clients.erase(client_fd);
}

void Server::run() {
	while (true) {
		this->handle_events();
	}
}