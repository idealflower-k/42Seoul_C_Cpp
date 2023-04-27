#include <iostream>
#include <ctime>
#include <iomanip>

int	main(void) {
    std::time_t t = std::time(NULL);
    char timestamp[16];
    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::localtime(&t));
    std::cout << "[" << timestamp << "] ";
    return 0;
}