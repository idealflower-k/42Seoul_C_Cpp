#include "echo_server.hpp"

int main() {
	int server_fd, client_fd;
	struct sockaddr_in server_addr, client_addr;
	char buffer[1024];
	int port = 8080;

	// 소켓 생성
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("Socket failed");
		exit(EXIT_FAILURE);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(port);

	// 소켓 바인딩
	if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		perror("Bind failed");
		close(server_fd);
		exit(EXIT_FAILURE);
	}

	// 소켓이 클라이언트 연결을 기다림
	if (listen(server_fd, 1) < 0) {
		perror("Listen failed");
		close(server_fd);
		exit(EXIT_FAILURE);
	}

	int addrlen = sizeof(client_addr);

	// 클라이언트 연결 수락
	if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen)) < 0) {
		perror("Accept failed");
		close(server_fd);
		exit(EXIT_FAILURE);
	}

	while (true) {
		int read_val = read(client_fd, buffer, 1024);
		if (read_val == 0) {
			std::cout << "Client disconnected" << std::endl;
			break;
		}
		buffer[read_val] = '\0';
		std::cout << "Client: " << buffer << std::endl;

		send(client_fd, buffer, read_val, 0);
	}

	close(client_fd);
	close(server_fd);

	return 0;
}
