#ifndef CLIENTHANDLER_HPP
#define CLIENTHANDLER_HPP

#include "webserv.hpp"

class ClientHandler {
   private:
	int fd;
	std::string buffer;
	static const int BUFFER_SIZE = 1024;

   public:
	ClientHandler(int fd);

	void read_data();
	void write_data(const std::string& data);
}

#endif