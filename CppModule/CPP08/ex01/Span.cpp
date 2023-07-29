/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:12:22 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/29 17:39:30 by sanghwal         ###   ########seoul.kr  */
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

void Span::addNumber(std::vector<int>::iterator begin,
                     std::vector<int>::iterator end) {
  if (std::distance(begin, end) + this->storage.size() <= this->max_size) {
    this->storage.insert(this->storage.end(), begin, end);
  } else
    throw std::length_error("storage is full!!!\n");
}

unsigned int Span::shortestSpan() const {
  if (this->storage.size() < 2)
    throw std::length_error("Not enough data in storage!!!\n");

  std::vector<int> temp = this->storage;
  std::sort(temp.begin(), temp.end());

  unsigned int min_dist = UINT_MAX;
  std::vector<int>::iterator min1;
  std::vector<int>::iterator min2;
  for (std::vector<int>::iterator itr = temp.begin(); itr != temp.end();
       ++itr) {
    if (itr + 1 != temp.end()) {
      unsigned int data = UINT_MAX;
      if (*itr < 0 && *(itr + 1) > 0)
        data = static_cast<unsigned int>(std::abs(*itr) + *(itr + 1));
      else {
        data = static_cast<unsigned int>(*(itr + 1) - *itr);
      }
      min_dist = min_dist < data ? min_dist : data;
      min1 = min_dist < data ? min1 : itr;
      min2 = min_dist < data ? min2 : itr + 1;
    }
  }
  std::cout << "min1: " << *min1 << ", min2: " << *min2 << "\n";
  return (min_dist);
}

Span::~Span() { std::cout << "[Span] Destructor called\n"; }
