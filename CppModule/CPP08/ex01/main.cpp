#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>

#include "Span.hpp"

// test basic
int main(void) {
  Span span1(10);
  try {
    span1.addNumber(-3);
    span1.addNumber(-1);
    span1.addNumber(17);
    span1.addNumber(9);
    span1.addNumber(11);

    std::cout << span1.shortestSpan() << "\n";
    std::cout << span1.longestSpan() << "\n";

  } catch (std::exception& e) {
    std::cerr << e.what();
  }
}

// test 15000
// int main(void) {
//   std::srand(static_cast<unsigned int>(std::time(0)));
//   Span span1(15000);
//   std::vector<int> data;
//   for (int i = 0; i < 15000; ++i) {
//     data.push_back(std::rand());
//   }
//   try {
//     span1.addNumber(data.begin(), data.end());
//     std::cout << span1.shortestSpan() << "\n";
//     std::cout << span1.longestSpan() << "\n";
//   } catch (std::exception& e) {
//     std::cerr << e.what();
//   }
//   return (0);
// }
