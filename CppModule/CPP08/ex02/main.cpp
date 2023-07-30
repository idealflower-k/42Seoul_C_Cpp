/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:26:03 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/30 17:39:54 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <list>
#include <vector>

#include "MutantStack.hpp"

int main(void) {
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << mstack.top() << " is top\n";

  mstack.pop();

  std::cout << mstack.size() << " is size\n";

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  MutantStack<int>::iterator itr = mstack.begin();
  MutantStack<int>::iterator eitr = mstack.end();

  ++itr;
  --itr;
  std::cout << "data in stack\n";
  while (itr != eitr) {
    std::cout << *itr << "\n";
    ++itr;
  }
  std::stack<int> s(mstack);
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

//   std::list<int>::iterator itr = my_list.begin();
//   std::list<int>::iterator eitr = my_list.end();

//   ++itr;
//   --itr;
//   std::cout << "data in list\n";
//   while (itr != eitr) {
//     std::cout << *itr << "\n";
//     ++itr;
//   }
//   std::list<int> s(my_list);
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

//   std::vector<int>::iterator itr = my_vector.begin();
//   std::vector<int>::iterator eitr = my_vector.end();

//   ++itr;
//   --itr;
//   std::cout << "data in vector\n";
//   while (itr != eitr) {
//     std::cout << *itr << "\n";
//     ++itr;
//   }
//   std::vector<int> s(my_vector);
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

//   std::deque<int>::iterator itr = my_deque.begin();
//   std::deque<int>::iterator eitr = my_deque.end();

//   ++itr;
//   --itr;
//   std::cout << "data in deque\n";
//   while (itr != eitr) {
//     std::cout << *itr << "\n";
//     ++itr;
//   }
//   std::deque<int> s(my_deque);
//   return (0);
// }
