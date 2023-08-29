/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:44:53 by sanghwal          #+#    #+#             */
/*   Updated: 2023/08/29 16:52:31 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
void swap(T* a, T* b) {
  T temp = *a;
  *a = *b;
  *b = temp;
}

template <typename T>
T min(const T& a, const T& b) {
  return (b <= a ? b : a);
}

template <typename T>
T max(const T& a, const T& b) {
  return (b >= a ? b : a);
}

#endif
