#include "RPN.hpp"

int main(int ac, char const **av) {
  if (ac != 2) {
    std::cout << "usage: " << av[0] << " [input string]" << std::endl;
    return 1;
  }

  try {
    RPN rpn(av[1]);
    rpn.calculator();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
