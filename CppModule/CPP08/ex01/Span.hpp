#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <limits>
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

  template <typename InputItr>
  void addNumber(InputItr begin, InputItr end) {
    if (std::distance(begin, end) + this->storage.size() <= this->max_size) {
      this->storage.insert(this->storage.end(), begin, end);
    } else
      throw std::length_error("storage is full!!!\n");
  }

  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;

  ~Span();
};

#endif
