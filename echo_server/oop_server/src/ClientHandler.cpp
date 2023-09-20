#include "ClientHandler.hpp"

ClientHandler::ClientHandler(int fd, const sockaddr_in& client_addr) : _fd(fd), _client_addr(client_addr) {
	std::cout << "client create: " << this->_fd << "\n";
}

int ClientHandler::read_data() {
	std::vector<char> buf(this->BUFFER_SIZE);
	int n = read(this->_fd, buf.data(), buf.size());

	if (n > 0) {
		buf.push_back('\n');
		this->buffer.insert(this->buffer.end(), buf.begin(), buf.end());
	}
	return (n);
}

int ClientHandler::write_data() {
	int n = write(this->_fd, buffer.data(), buffer.size());

	return (n);
}

void ClientHandler::erase_buffer(int n) {
	if (n <= this->buffer.size())
		this->buffer.erase(this->buffer.begin(), this->buffer.begin() + n);
}

bool ClientHandler::is_empty_buffer() {
	return (this->buffer.empty());
}