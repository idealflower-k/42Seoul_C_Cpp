#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

#include <iostream>
#include <string>

#include "Data.hpp"

class Serializer {
 private:
  Serializer();
  Serializer(const Serializer& origin);
  Serializer& operator=(const Serializer& origin);
  ~Serializer();

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif
