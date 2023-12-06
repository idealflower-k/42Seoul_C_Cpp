/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:24:48 by sanghwal          #+#    #+#             */
/*   Updated: 2023/12/06 21:15:21 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cmath>
#include <iostream>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

template <typename A, typename F>
void iter(A* arr, int len, F& func) {
  std::cerr << "non-const iter\n";
  for (int i = 0; i < len; i++) func(arr[i]);
}
template <typename A, typename F>
void iter(const A* arr, int len, const F& func) {
  std::cerr << "const iter\n";
  for (int i = 0; i < len; i++) func(arr[i]);
}

template <typename A, typename F>
void iter(A* arr, int len, const F& func) {
  std::cerr << "const func iter\n";
  for (int i = 0; i < len; i++) func(arr[i]);
}

template <typename A, typename F>
void iter(A* arr, int len, F (*func)(A)) {
  std::cerr << "function pointer iter\n";
  for (int i = 0; i < len; i++) (*func)(arr[i]);
}

template <typename A, typename F>
void iter(const A* arr, int len, F (*func)(A)) {
  std::cerr << "function pointer iter\n";
  for (int i = 0; i < len; i++) (*func)(arr[i]);
}

template <typename A, typename F>
void iter(const A* arr, int len, const F (*func)(A)) {
  std::cerr << "function pointer iter\n";
  for (int i = 0; i < len; i++) (*func)(arr[i]);
}

template <typename T>
void plusOne(T& data) {
  data++;
}

template <typename T>
void printData(const T& data) {
  std::cout << data << " ";
}

#endif
