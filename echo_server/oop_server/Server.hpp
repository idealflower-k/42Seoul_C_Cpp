#ifndef SERVER_HPP
#define SERVER_HPP

#include "ClientHandler.hpp"
#include "webserv.hpp"

class ClientHandler;

class Server {
   private:
	void init_server();
	void handle_events();
	void accept_client();
	void change_events(short filter, u_short flags, u_int fflags, int64_t data, void* udata);
	void disconnect_client(int client_fd);

	const int MAX_EVENTS = 10;

	int server_fd;
	int kq;
	int port;
	sockaddr_in server_addr;

	std::map<int, Clienthandler*> clients;
	std::vector<struct kevent> change_list;
	struct kevent event_list[10];

   public:
	Server(int port);
	void run();
}

#endif