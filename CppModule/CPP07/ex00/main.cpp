#include <iostream>
#include <string>
#include <cstdlib>

#include "whatever.hpp"

struct test {
  int data;
};

int main(void) {
  int oneInt = 1;
  int twoInt = 2;

  ::swap(oneInt, twoInt);
  std::cout << "oneInt = " << oneInt << ", twoInt = " << twoInt << "\n";
  std::cout << "min(oneInt, twoInt) = " << ::min(oneInt, twoInt) << "\n";
  std::cout << "max(oneInt, twoInt) = " << ::max(oneInt, twoInt) << "\n";

  std::string oneStr = "chaine1";
  std::string twoStr = "chaine2";

  ::swap(oneStr, twoStr);
  std::cout << "oneStr = " << oneStr << ", twoStr = " << twoStr << "\n";
  std::cout << "min(oneStr, twoStr) = " << ::min(oneStr, twoStr) << "\n";
  std::cout << "max(oneStr, twoStr) = " << ::max(oneStr, twoStr) << "\n";

  const char *cStr1 = "abc";
  const char *cStr2 = "bbc";

  // ::swap(cStr1, cStr2);
  std::cout << "cStr1 = " << cStr1 << ", cStr2 = " << cStr2 << "\n";
  std::cout << "min(cStr1, cStr2) = " << ::min(cStr1, cStr2) << "\n";
  std::cout << "max(cStr1, cStr2) = " << ::max(*cStr1, *cStr2) << "\n";

  double d1 = 123.45;
  double d2 = 123.46;

  ::swap(d1, d2);
  std::cout << "d1 = " << d1 << ", d2 = " << d2 << "\n";
  std::cout << "min(d1, d2) = " << ::min(d1, d2) << "\n";
  std::cout << "max(d1, d2) = " << ::max(d1, d2) << "\n";

  test test1 = {1};
  test test2 = {2};

  ::swap(test1, test2);
  std::cout << "test1 = " << test1.data << ", test2 = " << test2.data << "\n";
  std::cout << "min(test1, test2) = " << ::min(test1.data, test2.data) << "\n";
  std::cout << "max(test1, test2) = " << ::max(test1.data, test2.data) << "\n";

  system("leaks whatever");
  return (0);
}
