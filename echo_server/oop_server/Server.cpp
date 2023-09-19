#include "Server.hpp"

// class Server {
//    private:
// 	void init_server();
// 	void handle_events();
// 	void accept_client();
// 	void disconnect_client(int client_fd);

// 	const int MAX_EVENTS = 10;

// 	int server_fd;
// 	int kq;
// 	int port;
// 	sockaddr_in server_addr;

// 	std::map<int, ClientHandler*> clients;
// 	std::vector<struct kevent> change_list;
// 	struct kevent event_list[10];

//    public:
// 	Server(int port);
// 	void run();
// }

void Server::Server(int port) : port(port) {
	std::cout << "Server create\n";
	this->init_server();
}

void Server::init_server() {
	this->server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this.server_fd < 0)
		throw std::runtime_error("socket() failed\n");

	try {
		int opt = 1;
		if (setsockopt(this->server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
			throw std::runtime_error("setsockopt() failed\n");
		}

		std::memset(&server_addr, 0, sizeof(server_addr));
		server_addr.sin_family = AF_INET;
		server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
		server_addr.sin_port = htons(this->port);

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
		change_events(EVFILT_READ, EV_ADD, 0, 0, NULL);
	} catch (std::exception& e) {
		close(this->server_fd);
		throw;
	}
}

void Server::accept_client() {
	int client_fd = accept(this->server_fd, NULL, NULL);
	if (client_fd < 0)
		throw std::runtime_error("accept error\n");
	Clinets[client_fd] = "";

	fcntl(client_fd, F_SETFL, O_NONBLOCK);
}

void Server::handle_events() {
	int new_events = kevent(this->kq, &this->change_list[0], this->change_list.size(), this->event_list, 10, NULL);
	if (... here)
}

void Server::change_events(short filter, u_short flags, u_int fflags, int64_t data, void* udata) {
	struct kevent temp_event;

	EV_SET(&temp_event, static_cast<uintptr_t>(this->server_fd), filter, flags, fflags, data, udata);
	this->change_list.push_back(temp_event);
}