#include "ClientHandler.hpp"
#include "Server.hpp"

int main(void) {
	try {
		Server server1(8080);
		server1.run();
	} catch (std::exception& e) {
		std::cerr << e.what();
	}
}