/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:48:40 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/28 14:00:49 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.hpp"

// void check(void) { system("leaks array"); }

int main(void) {
  Array<int> arr1(5);
  Array<char> arr2(5);
  Array<double> arr3(5);

  // atexit(check);

  std::cout << "==test int_arr==\n";
  for (unsigned int i = 0; i < arr1.size(); i++) arr1[i] = i;
  for (unsigned int i = 0; i < arr1.size(); i++) std::cout << arr1[i] << " ";
  std::cout << "\n";

  std::cout << "==test char_arr==\n";
  for (unsigned int i = 0; i < arr2.size(); i++)
    arr2[i] = static_cast<char>(i + 'A');
  for (unsigned int i = 0; i < arr2.size(); i++) std::cout << arr2[i] << " ";
  std::cout << "\n";

  std::cout << "==test double_arr==\n";
  for (unsigned int i = 0; i < arr3.size(); i++) arr3[i] = ('a' + i);
  for (unsigned int i = 0; i < arr3.size(); i++)
    std::cout << std::showpoint << arr3[i] << " ";
  std::cout << "\n";

  return (0);
}
