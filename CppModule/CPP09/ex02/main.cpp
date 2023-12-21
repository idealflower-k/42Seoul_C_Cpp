#include "PmergeMe.hpp"

int main(int ac, char** av) {
  if (ac < 2) {
    std::cout << "Usage: " << av[0] << " [integers]" << std::endl;
    return 1;
  }
  try {
    PmergeMe pm(&av[1]);
    pm.run();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  } catch (...) {
    std::cout << "Unknown error" << std::endl;
  }

  return 0;
}
