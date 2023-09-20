#ifndef CLIENTHANDLER_HPP
#define CLIENTHANDLER_HPP

#include "webserv.hpp"

class ClientHandler {
   private:
	int _fd;
	std::vector<char> buffer;
	static const int BUFFER_SIZE = 1024;
	struct sockaddr_in _client_addr;

   public:
	ClientHandler(int fd, const sockaddr_in& client_addr);

	int read_data();
	int write_data();
	void erase_buffer(int n);
	bool is_empty_buffer();
};

#endif