#include <deque>
#include <list>
#include <vector>

#include "MutantStack.hpp"

int main(void) {
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << mstack.top() << " is top\n";

  std::cout << mstack.top() << " is pop\n";
  mstack.pop();

  std::cout << "size is " << mstack.size() << "\n";
  std::cout << mstack.top() << " is top\n";

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  // MutantStack<int>::const_iterator citr = mstack.begin();
  // MutantStack<int>::const_iterator ceitr = mstack.end();
  // *citr = 42;
  // *ceitr = 42;

  std::cout << "data in mstack\n";
  for (MutantStack<int>::iterator itr = mstack.begin(); itr != mstack.end();
       ++itr) {
    std::cout << *itr << ", ";
  }

  std::stack<int> copyStack(mstack);
  std::cout << "\ndata in copyStack\n";
  while (!copyStack.empty()) {
    std::cout << copyStack.top() << ", ";
    copyStack.pop();
  }

  return (0);
}

// int main(void) {
//   std::list<int> my_list;

//   my_list.push_back(5);
//   my_list.push_back(17);

//   std::cout << my_list.back() << " is top\n";

//   my_list.pop_back();

//   std::cout << my_list.size() << " is size\n";

//   my_list.push_back(3);
//   my_list.push_back(5);
//   my_list.push_back(737);
//   my_list.push_back(0);

//   std::cout << "data in list\n";
//   for (std::list<int>::iterator itr = my_list.begin(); itr != my_list.end();
//        ++itr) {
//     std::cout << *itr << ", ";
//   }
//   std::list<int> copyList(my_list);
//   std::cout << "\ndata in copyList\n";
//   for (std::list<int>::iterator itr = copyList.begin(); itr !=
//   copyList.end();
//        ++itr) {
//     std::cout << *itr << ", ";
//   }
//   return (0);
// }

// int main(void) {
//   std::vector<int> my_vector;

//   my_vector.push_back(5);
//   my_vector.push_back(17);

//   std::cout << my_vector.back() << " is top\n";

//   my_vector.pop_back();

//   std::cout << my_vector.size() << " is size\n";

//   my_vector.push_back(3);
//   my_vector.push_back(5);
//   my_vector.push_back(737);
//   my_vector.push_back(0);

//   std::cout << "data in vector\n";
//   for (std::vector<int>::iterator itr = my_vector.begin();
//        itr != my_vector.end(); ++itr) {
//     std::cout << *itr << ", ";
//   }

//   std::vector<int> copyVector(my_vector);
//   std::cout << "\ndata in copyVector\n";
//   for (std::vector<int>::iterator itr = copyVector.begin();
//        itr != copyVector.end(); ++itr) {
//     std::cout << *itr << ", ";
//   }
//   return (0);
// }

// int main(void) {
//   std::deque<int> my_deque;

//   my_deque.push_back(5);
//   my_deque.push_back(17);

//   std::cout << my_deque.back() << " is top\n";

//   my_deque.pop_back();

//   std::cout << my_deque.size() << " is size\n";

//   my_deque.push_back(3);
//   my_deque.push_back(5);
//   my_deque.push_back(737);
//   my_deque.push_back(0);

//   std::cout << "data in deque\n";
//   for (std::deque<int>::iterator itr = my_deque.begin(); itr !=
//   my_deque.end();
//        ++itr) {
//     std::cout << *itr << ", ";
//   }
//   std::deque<int> copyDeque(my_deque);
//   std::cout << "\ndata in copyDeque\n";
//   for (std::deque<int>::iterator itr = copyDeque.begin();
//        itr != copyDeque.end(); ++itr) {
//     std::cout << *itr << ", ";
//   }
//   return (0);
// }
