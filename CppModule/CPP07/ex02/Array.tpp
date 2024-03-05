#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), arr_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), arr_size(n) {}

template <typename T>
Array<T>::Array(const Array<T>& origin)
    : array(origin.arr_size > 0 ? new T[origin.arr_size]() : NULL),
      arr_size(origin.arr_size) {
  for (unsigned int i = 0; i < arr_size; i++) array[i] = origin.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& origin) {
  if (this != &origin) {
    delete[] array;
    array = origin.arr_size > 0 ? new T[origin.arr_size]() : NULL;
    arr_size = origin.arr_size;
    for (unsigned int i = 0; i < arr_size; i++) array[i] = origin.array[i];
  }
  return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int n) {
  if (n > this->arr_size || this->arr_size == 0)
    throw std::out_of_range("Index out of range!!\n");
  return (this->array[n]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const {
  if (n > this->arr_size || this->arr_size == 0)
    throw std::out_of_range("Index out of range!!\n");
  return (this->array[n]);
}

template <typename T>
unsigned int Array<T>::size() const {
  return (this->arr_size);
}

template <typename T>
Array<T>::~Array() {
  std::cout << "[Array] Destructor called\n";
  delete[] this->array;
}
