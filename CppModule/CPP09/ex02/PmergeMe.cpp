#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** av) { initData(av); }

PmergeMe::~PmergeMe() {}

void PmergeMe::initData(char** av) {
  std::string str;

  for (size_t i = 0; av[i]; ++i) {
    str = av[i];
    if (!this->validData(str)) throw std::invalid_argument(ERROR);
    int data = this->strToInt(str);
    this->_vec.push_back(data);
    this->_deq.push_back(data);
  }
  this->printInput();
}

int PmergeMe::strToInt(std::string str) {
  std::stringstream ss(str);
  int data;
  ss >> data;
  return data;
}

bool PmergeMe::validData(std::string data) {
  if (data.empty()) return false;

  for (size_t i = 0; i < data.length(); ++i) {
    if (!std::isdigit(data[i])) return false;
  }

  std::stringstream ss(data);
  int IntData;
  ss >> IntData;

  if (ss.fail()) return false;

  return true;
}

void PmergeMe::printInput() {
  std::cout << "Before: ";
  for (size_t i = 0; i < this->_vec.size(); ++i) {
    std::cout << this->_vec[i];
    if (i != this->_vec.size() - 1) std::cout << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::printSort() {
  std::cout << "After: ";
  this->printVector();
}

void PmergeMe::printVector() {
  for (size_t i = 0; i < this->_vec.size(); ++i) {
    std::cout << this->_vec[i];
    if (i != this->_vec.size() - 1) std::cout << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::printDeque() {
  for (size_t i = 0; i < this->_deq.size(); ++i) {
    std::cout << this->_deq[i];
    if (i != this->_deq.size() - 1) std::cout << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::fordJohnsonAlgorithmVector(size_t size) {
  this->pairSortVector(size);
  size_t pair = this->_vec.size() / size;
  if (pair == 1) {
    this->printVector();
    exit(0);
  }
  this->fordJohnsonAlgorithmVector(size * 2);
  // this->mergeInsertionSortVector(0, this->_vec.size() - 1);
}

void PmergeMe::pairSortVector(size_t size) {
  if (size == 1) return;
  size_t pair = this->_vec.size() / size;
  size_t range = size / 2;
  for (size_t i = 0; i < pair; ++i) {
    size_t first = i * size;
    size_t second = first + range;
    if (this->_vec[first] < this->_vec[second]) {
      for (size_t j = 0; j < range; ++j) {
        std::swap(this->_vec[first + j], this->_vec[second + j]);
      }
    }
  }
}

void PmergeMe::run() {
  std::cout << "Running..." << std::endl;
  this->fordJohnsonAlgorithmVector(1);
}
