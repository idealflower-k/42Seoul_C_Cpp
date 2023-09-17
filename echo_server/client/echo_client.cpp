#include "echo_client.hpp"

int main() {
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int port = 8080;

    // 소켓 생성
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // 서버의 IP 주소 설정 (여기서는 localhost)
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    // 서버에 연결
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    std::string message;
    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, message);

        send(sock_fd, message.c_str(), message.length(), 0);

        int valread = read(sock_fd, buffer, 1024);
        buffer[valread] = '\0';
        std::cout << "Server: " << buffer << std::endl;
    }

    close(sock_fd);

    return 0;
}
