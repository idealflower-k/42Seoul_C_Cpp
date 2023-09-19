#include <iostream>
#include <cstring>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Socket creation failed\n";
        return -1;
    }

    sockaddr_in server_addr;
    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connection failed\n";
        close(sockfd);
        return -1;
    }

    std::string message;
    while (true) {
        std::cout << "Enter message: ";
        std::getline(std::cin, message);

        if (send(sockfd, message.c_str(), message.size(), 0) < 0) {
            std::cerr << "Send failed\n";
            break;
        }

        char buffer[1024];
        int len = recv(sockfd, buffer, 1024, 0);
        if (len < 0) {
            std::cerr << "Receive failed\n";
            break;
        }

        if (len == 0) {
            std::cout << "Server closed connection\n";
            break;
        }

        std::cout << "Received from server: " << std::string(buffer, len) << "\n";
    }

    close(sockfd);
    return 0;
}
