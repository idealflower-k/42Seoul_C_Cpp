#include "RPN.hpp"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cout << "usage: ./ex01 [input string]" << std::endl;
    return 1;
  }

  try {
    RPN rpn(argv[1]);
    rpn.calculator();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
