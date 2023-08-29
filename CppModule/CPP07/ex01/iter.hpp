/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:24:48 by sanghwal          #+#    #+#             */
/*   Updated: 2023/08/29 16:24:43 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cmath>
#include <iostream>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

template <typename A, typename F>
void iter(A* arr, int len, const F& func) {
  for (int i = 0; i < len; i++) func(arr[i]);
}

template <typename T>
void plusOne(T& data) {
  data++;
}

template <typename T>
void printData(T& data) {
  std::cout << data << " ";
}

#endif
