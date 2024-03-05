#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
  std::string name;
  unsigned int age;
  unsigned int level;

  Data() : name(""), age(0), level(0){};
  Data(std::string name, unsigned int age, unsigned int level)
      : name(name), age(age), level(level){};
};

#endif
