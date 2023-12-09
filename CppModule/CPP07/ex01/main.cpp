#include "iter.hpp"

void sqrtWrapper(double& data) { data = std::pow(data, 2); }

int main(void) {
  const int int_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  char char_arr[10] = "abcdefghi";
  double double_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  ::iter(int_arr, ARRAY_SIZE(int_arr), ::printData<int>);
  std::cout << "\n";
  // ::iter(int_arr, ARRAY_SIZE(int_arr), ::plusOne<int>);
  // ::iter(int_arr, ARRAY_SIZE(int_arr), ::printData<int>);
  // std::cout << "\n";

  ::iter(char_arr, ARRAY_SIZE(char_arr), ::printData<char>);
  std::cout << "\n";
  ::iter(char_arr, ARRAY_SIZE(char_arr), ::plusOne<char>);
  ::iter(char_arr, ARRAY_SIZE(char_arr), ::printData<char>);
  std::cout << "\n";

  ::iter(double_arr, ARRAY_SIZE(double_arr), ::printData<double>);
  std::cout << "\n";
  ::iter(double_arr, ARRAY_SIZE(double_arr), sqrtWrapper);

  ::iter(double_arr, ARRAY_SIZE(double_arr), ::printData<double>);
  std::cout << "\n";

  return (0);
}
