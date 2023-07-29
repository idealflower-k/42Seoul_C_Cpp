/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:20:46 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/29 17:43:51 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "Span.hpp"

// test basic
int main(void) {
  Span span1(5);
  try {
    span1.addNumber(6);
    span1.addNumber(3);
    span1.addNumber(17);
    span1.addNumber(9);
    span1.addNumber(11);
    std::cout << span1.shortestSpan() << "\n";
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
}

// test 15000
// int main(void) {
//   std::srand(static_cast<unsigned int>(std::time(0)));
//   Span span1(15000);
//   std::vector<int> data;
//   for (int i = 0; i < 20; ++i) {
//     data.push_back(std::rand());
//   }
//   try {
//     span1.addNumber(data.begin(), data.end());
//     std::cout << span1.shortestSpan() << "\n";
//   } catch (std::exception& e) {
//     std::cerr << e.what();
//   }
//   return (0);
// }
