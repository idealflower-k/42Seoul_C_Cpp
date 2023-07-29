/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:33:17 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/29 17:33:57 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <climits>
#include <exception>
#include <iostream>
#include <vector>

class Span {
 private:
  std::vector<int> storage;
  unsigned int max_size;
  Span();

 public:
  Span(unsigned int N);
  Span(const Span& origin);
  Span& operator=(const Span& origin);

  void addNumber(int num);
  void addNumber(std::vector<int>::iterator begin,
                 std::vector<int>::iterator end);
  unsigned int shortestSpan() const;
  // unsigned int longestSpan() const;

  ~Span();
};

#endif
