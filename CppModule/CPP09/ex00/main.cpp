#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
  try {
    if (ac != 2) {
      std::cout << "usage: " << av[0] << " [input_file]" << std::endl;
      return 1;
    }
    BitcoinExchange bitcoin(av[1]);
    bitcoin.convert();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
