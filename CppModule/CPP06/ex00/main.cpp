#include "ScalarConverter.hpp"

int main(int ac, char** av) {
  if (ac != 2) {
    std::cerr << "Wrong arguments\n";
    return (1);
  }

  try {
    ScalarConverter::convert(av[1]);
  } catch (std::exception& e) {
    std::cerr << "Exception!!: " << e.what();
  }

  return (0);
}
