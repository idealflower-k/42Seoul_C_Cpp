/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:12:22 by sanghwal          #+#    #+#             */
/*   Updated: 2023/12/16 19:38:47 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span& origin)
    : storage(origin.storage), max_size(origin.max_size) {}

Span& Span::operator=(const Span& origin) {
  if (this != &origin) {
    storage = origin.storage;
    max_size = origin.max_size;
  }
  return (*this);
}

void Span::addNumber(int num) {
  if (this->max_size > this->storage.size())
    this->storage.push_back(num);
  else
    throw std::length_error("storage is full!!!\n");
}

unsigned int Span::longestSpan() const {
  if (this->storage.size() < 2)
    throw std::length_error("Not enough data in storage!!!\n");

  std::vector<int> temp = this->storage;
  std::sort(temp.begin(), temp.end());

  unsigned int max_dist = std::numeric_limits<unsigned int>::min();
  int begin_data = *(temp.begin());
  int end_data = *(temp.end() - 1);

  if (begin_data < 0 && end_data > 0)
    max_dist = static_cast<unsigned int>(std::abs(begin_data) + end_data);
  else
    max_dist = static_cast<unsigned int>(end_data - begin_data);
  return (max_dist);
}

unsigned int Span::shortestSpan() const {
  if (this->storage.size() < 2)
    throw std::length_error("Not enough data in storage!!!\n");

  std::vector<int> temp = this->storage;
  std::sort(temp.begin(), temp.end());

  unsigned int min_dist = std::numeric_limits<unsigned int>::max();
  unsigned int dist = std::numeric_limits<unsigned int>::max();
  for (std::vector<int>::iterator itr = temp.begin(); itr != temp.end();
       ++itr) {
    if (itr + 1 != temp.end()) {
      std::vector<int>::iterator nextItr = itr + 1;
      dist = std::numeric_limits<unsigned int>::max();
      if (*itr < 0 && *(nextItr) > 0)
        dist = static_cast<unsigned int>(std::abs(*itr) + *(nextItr));
      else {
        dist = static_cast<unsigned int>(*(nextItr) - *itr);
      }
      min_dist = std::min(min_dist, dist);
    }
  }
  return (min_dist);
}

Span::~Span() { std::cout << "[Span] Destructor called\n"; }
