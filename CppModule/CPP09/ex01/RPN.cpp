#include "RPN.hpp"

int (RPN::*RPN::_operators[])(int, int) = {
    &RPN::addition, &RPN::subtraction, &RPN::division, &RPN::multiplication};
std::string RPN::_operatorsStr[] = {"+", "-", "/", "*"};

RPN::RPN(std::string input) : _input(input) {}

void RPN::calculator() {
  std::string str;

  while (this->_input.length() > 0) {
    str = this->getOneStr();
    if (!str.empty()) this->route(str);
  }

  this->printResult();
}

void RPN::setData(int data) { _storage.push(data); }

std::string RPN::getOneStr() {
  while (std::isspace(this->_input[0])) this->_input.erase(0, 1);

  std::istringstream iss(_input);
  std::string str;

  iss >> str;
  this->_input.erase(0, str.length());
  return str;
}

void RPN::calData(std::string str) {
  int index = 0;
  int size = sizeof(this->_operatorsStr) / sizeof(std::string);

  for (int i = 0; i < size; ++i) {
    if (str.compare(this->_operatorsStr[i]) == 0) {
      index = i;
      break;
    }
  }

  int result = this->calOp(index);
  this->_storage.push(result);
}

int RPN::calOp(size_t op) {
  std::stack<int> data = this->getTwoData();
  int result = 0;

  int data1 = data.top();
  data.pop();
  int data2 = data.top();
  data.pop();
  result = (this->*_operators[op])(data1, data2);

  return result;
}

std::stack<int> RPN::getTwoData() {
  std::stack<int> data;

  if (this->_storage.size() < 2) this->throwException();

  data.push(this->_storage.top());
  this->_storage.pop();
  data.push(this->_storage.top());
  this->_storage.pop();

  return data;
}

bool RPN::validStr(std::string str) {
  if (str.size() != 1) return false;

  if (isdigit(str[0]))
    return true;
  else {
    int size = sizeof(this->_operatorsStr) / sizeof(std::string);
    for (int i = 0; i < size; ++i) {
      if (str.compare(this->_operatorsStr[i]) == 0) return true;
    }
  }

  return false;
}

void RPN::route(std::string str) {
  if (this->validStr(str) == false) this->throwException();

  if (isdigit(str[0]))
    this->setData(std::atoi(str.c_str()));
  else
    this->calData(str);
}

void RPN::printResult() {
  if (this->_storage.size() != 1) this->throwException();

  std::cout << this->_storage.top() << std::endl;
}

int RPN::addition(int data1, int data2) { return data1 + data2; }

int RPN::subtraction(int data1, int data2) { return data1 - data2; }

int RPN::multiplication(int data1, int data2) { return data1 * data2; }

int RPN::division(int data1, int data2) {
  if (data2 == 0) this->throwException();

  return data1 / data2;
}

void RPN::throwException() { throw std::runtime_error(ERROR); }

RPN::~RPN() {}
