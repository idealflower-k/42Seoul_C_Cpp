/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:10:49 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/28 20:31:36 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void printContainer(T& contain) {
  for (typename T::iterator itr = contain.begin(); itr != contain.end(); ++itr)
    std::cout << *itr << " ";
  std::cout << "\n";
}

int main(void) {
  std::vector<int> arr1;
  for (int i = 0; i < 10; ++i) arr1.push_back(i);
  printContainer(arr1);
  std::vector<int>::const_iterator itr1 = ::easyfind(arr1, 3);
  if (itr1 != arr1.end()) std::cout << "Find in vector!!: " << *itr1 << "\n";

  std::list<int> lst1;
  for (int i = 0; i < 10; ++i) lst1.push_back(i);
  printContainer(lst1);
  std::list<int>::const_iterator itr2 = ::easyfind(lst1, 2);
  if (itr2 != lst1.end()) std::cout << "Find in list!!: " << *itr2 << "\n";

  std::deque<int> deque1;
  for (int i = 0; i < 10; ++i) deque1.push_back(i);
  printContainer(deque1);
  std::deque<int>::const_iterator itr3 = ::easyfind(deque1, 1);
  if (itr3 != deque1.end()) std::cout << "Find in deque!!: " << *itr3 << "\n";

  return (0);
}
