
#include <algorithm>
#include <iostream>
#include <vector>
template <typename T>
void print_vector(std::vector<T>& vec) {
  for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
       ++itr)
    std::cout << *itr << " ";
  std::cout << "\n";
}

int main(void) {
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);
  print_vector(vec);

  vec.insert(vec.begin() + 2, 15);
  print_vector(vec);
  vec.erase(vec.begin() + 3);
  print_vector(vec);
}
