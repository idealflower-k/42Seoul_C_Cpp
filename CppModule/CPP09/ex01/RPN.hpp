#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

#define ERROR "ERROR"

class RPN {
 private:
  static int (RPN::*_operators[])(int, int);
  static std::string _operatorsStr[];

  std::stack<int> _storage;
  std::string _input;

  std::string getOneStr();
  void route(std::string str);
  bool validStr(std::string str);
  void setData(int data);
  void calData(std::string str);
  std::stack<int> getTwoData();
  void printResult();
  int calOp(size_t op);
  int addition(int data1, int data2);
  int subtraction(int data1, int data2);
  int multiplication(int data1, int data2);
  int division(int data1, int data2);
  void throwException();

  RPN(const RPN& rpn);
  RPN& operator=(const RPN& rpn);
  RPN();

 public:
  RPN(std::string input);
  ~RPN();

  void calculator();
};

#endif
