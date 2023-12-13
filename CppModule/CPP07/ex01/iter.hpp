#ifndef ITER_HPP
#define ITER_HPP

#include <cmath>
#include <iostream>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

template <typename A, typename F>
void iter(A* arr, int len, F& func) {
  for (int i = 0; i < len; i++) func(arr[i]);
}

template <typename A, typename F>
void iter(const A* arr, int len, const F& func) {
  for (int i = 0; i < len; i++) func(arr[i]);
}

template <typename A, typename F>
void iter(const A* arr, int len, F& func) {
  for (int i = 0; i < len; i++) func(arr[i]);
}

template <typename A, typename F>
void iter(A* arr, int len, const F& func) {
  for (int i = 0; i < len; i++) func(arr[i]);
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
