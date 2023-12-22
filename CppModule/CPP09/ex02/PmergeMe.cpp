#include "PmergeMe.hpp"

// standard C++98

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
  this->setJacobsThalSequence();
  this->printInput();
}

void PmergeMe::setJacobsThalSequence() {
  size_t size = this->_vec.size(), prev = 0, curr = 1, next;

  this->_jacobsThalSequence.push_back(prev);
  this->_jacobsThalSequence.push_back(curr);

  // int overflow check
  for (size_t i = 2; i <= size; ++i) {
    if (curr > INT_MAX - 2 * prev) throw std::overflow_error(ERROR);

    next = curr + 2 * prev;
    if (next >= size) {
      this->_jacobsThalSequence.push_back(size);
      break;
    }
    this->_jacobsThalSequence.push_back(next);
    prev = curr;
    curr = next;
  }
  std::cout << "Jacobs-Thal Sequence: ";
  for (size_t i = 0; i < this->_jacobsThalSequence.size(); ++i) {
    std::cout << this->_jacobsThalSequence[i];
    if (i != this->_jacobsThalSequence.size() - 1) std::cout << " ";
  }
  std::cout << std::endl;
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
  std::cout << "size = " << size << " pair = " << this->_vec.size() / size
            << " : ";
  this->printVector();
  size_t pair = this->_vec.size() / size;
  if (pair == 1) {
    return;
  }
  this->fordJohnsonAlgorithmVector(size * 2);
  this->mergeInsertionSortVector(size);
}

void PmergeMe::pairSortVector(size_t size) {
  if (size == 1) return;
  size_t pair = this->_vec.size() / size;
  size_t range = size / 2;
  for (size_t i = 0; i < pair; ++i) {
    size_t first = i * size;
    size_t second = first + range;
    if (this->_vec[first] < this->_vec[second]) {
      std::swap_ranges(this->_vec.begin() + first,
                       this->_vec.begin() + first + range,
                       this->_vec.begin() + second);
    }
  }
}

void PmergeMe::mergeInsertionSortVector(size_t size) {
  // size_t pair = this->_vec.size() / size;
  size_t range = size / 2;
  size_t insertData = range;

  std::swap_ranges(this->_vec.begin(), this->_vec.begin() + range,
                   this->_vec.begin() + range);

  std::cout << "insertData: " << insertData << std::endl;
  std::cout << "jacob: " << this->getJacobsThalSequence(1) << std::endl;
  std::cout << "range = " << range << std::endl;
  std::cout << std::endl;
  std::cout << "after swap: ";
  this->printVector();

  exit(0);
}

std::vector<std::vector<int>::iterator> PmergeMe::makeMainChainVector(
    size_t size) {
  std::vector<std::vector<int>::iterator> mainChain;
  size_t pair = this->_vec.size() / size;

  for (size_t i = 0; i < pair; ++i) {
    size_t target = i * size;
    if (i == 1) mainChain.push_back(this->_vec.begin() + target - size / 2);
    mainChain.push_back(this->_vec.begin() + target);
  }
  return mainChain;
}

std::vector<std::vector<int>::iterator> PmergeMe::makePendElemtsVector(
    size_t size) {
  std::vector<std::vector<int>::iterator> pendElemts;
  size_t pair = this->_vec.size() / size;
  size_t range = size / 2;

  for (size_t i = 1; i < pair; ++i) {
    size_t target = i * size + range;
    pendElemts.push_back(this->_vec.begin() + target);
  }
  return pendElemts;
}

int PmergeMe::getJacobsThalSequence(size_t n) {
  return this->_jacobsThalSequence[n + 2];
}

void PmergeMe::run() {
  std::cout << "Running..." << std::endl;
  this->fordJohnsonAlgorithmVector(1);
}
