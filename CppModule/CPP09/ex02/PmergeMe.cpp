#include "PmergeMe.hpp"

static bool compareVector(std::vector<int>::iterator first,
                          std::vector<int>::iterator second) {
  return *first < *second;
}

static bool compareDeque(std::deque<int>::iterator first,
                         std::deque<int>::iterator second) {
  return *first < *second;
}

PmergeMe::PmergeMe(char** av) : _sizeN(0) { initData(av); }

PmergeMe::~PmergeMe() {}

void PmergeMe::initData(char** av) {
  std::string str;

  this->_vec.reserve((sizeof(av) / sizeof(av[0])) + 1);
  for (size_t i = 0; av[i]; ++i) {
    str = av[i];
    if (!this->validData(str)) throw std::invalid_argument(ERROR);
    int data = this->strToInt(str);
    this->_vec.push_back(data);
    this->_deq.push_back(data);
    this->_sizeN++;
  }
  this->setJacobsThalSequence();
}

void PmergeMe::setJacobsThalSequence() {
  size_t size = this->_sizeN, prev = 0, curr = 1, next;

  this->_jacobsThalSequence.push_back(prev);
  this->_jacobsThalSequence.push_back(curr);

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
  if (size > 1) {
    this->_jacobsThalSequence.erase(this->_jacobsThalSequence.begin() + 1);
    this->_jacobsThalSequence.erase(this->_jacobsThalSequence.begin() + 1);
  }
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
  this->printDeque();
}

void PmergeMe::printSort() {
  std::cout << "After: ";
  this->printDeque();
}

void PmergeMe::printVector() {
  for (size_t i = 0; i < this->_sizeN; ++i) {
    std::cout << this->_vec[i];
    if (i != this->_sizeN - 1) std::cout << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::printDeque() {
  for (size_t i = 0; i < this->_sizeN; ++i) {
    std::cout << this->_deq[i];
    if (i != this->_sizeN - 1) std::cout << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::fordJohnsonAlgorithmVector(size_t size) {
  size_t pair = this->_sizeN / size;

  this->pairSortVector(size);

  if (pair == 1) {
    return;
  }
  this->fordJohnsonAlgorithmVector(size * 2);
  this->mergeInsertionSortVector(size);
}

void PmergeMe::pairSortVector(size_t size) {
  if (size == 1) return;
  size_t pair = this->_sizeN / size;
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
  std::vector<std::vector<int>::iterator> mainChain =
      this->makeMainChainVector(size);
  std::vector<
      std::pair<std::vector<int>::iterator, std::vector<int>::iterator> >
      pendElemts = this->makePendElemtsVector(size);
  mainChain.insert(mainChain.begin(), pendElemts[0].first);
  pendElemts.erase(pendElemts.begin());

  this->mergeVector(mainChain, pendElemts);
  this->syncVector(size, mainChain);
}

void PmergeMe::mergeVector(
    std::vector<std::vector<int>::iterator>& mainChain,
    std::vector<std::pair<std::vector<int>::iterator,
                          std::vector<int>::iterator> >& pendElemts) {
  size_t pendElemtsSize = pendElemts.size();

  for (size_t i = 1, insertData = 0; insertData < pendElemtsSize; ++i) {
    size_t jacobs =
        std::min(static_cast<size_t>(this->getJacobsThalSequence(i) - 2),
                 pendElemtsSize - 1);
    if (jacobs >= pendElemtsSize) jacobs = pendElemtsSize - 1;
    size_t endIdx = (this->getJacobsThalSequence(i - 1) > 0)
                        ? this->getJacobsThalSequence(i - 1) - 1
                        : 0;
    while (endIdx <= jacobs) {
      std::vector<std::vector<int>::iterator>::iterator last = mainChain.end();
      if (pendElemts[jacobs].second != this->_vec.end()) {
        last = std::find(mainChain.begin(), mainChain.end(),
                         pendElemts[jacobs].second);
      }

      std::vector<std::vector<int>::iterator>::iterator target =
          std::upper_bound(mainChain.begin(), last, pendElemts[jacobs].first,
                           compareVector);

      mainChain.insert(target, pendElemts[jacobs].first);
      ++insertData;

      if (jacobs == endIdx) break;
      --jacobs;
    }
  }
}

void PmergeMe::syncVector(size_t size,
                          std::vector<std::vector<int>::iterator>& mainChain) {
  std::vector<int> temp;
  size_t pair = this->_sizeN / size;

  temp.reserve(this->_sizeN);
  for (size_t i = 0; i < mainChain.size(); ++i) {
    std::vector<int>::iterator target = mainChain[i];
    temp.insert(temp.end(), target, target + size);
  }

  temp.insert(temp.end(), this->_vec.begin() + (pair * size), this->_vec.end());
  this->_vec.swap(temp);
}

std::vector<std::vector<int>::iterator> PmergeMe::makeMainChainVector(
    size_t size) {
  std::vector<std::vector<int>::iterator> mainChain;
  size_t pair = this->_sizeN / (size * 2);
  mainChain.reserve(this->_sizeN);

  size_t target = 0;
  for (size_t i = 0; i < pair; ++i) {
    mainChain.push_back(this->_vec.begin() + target);
    target += size * 2;
  }
  return mainChain;
}

std::vector<std::pair<std::vector<int>::iterator, std::vector<int>::iterator> >
PmergeMe::makePendElemtsVector(size_t size) {
  std::vector<
      std::pair<std::vector<int>::iterator, std::vector<int>::iterator> >
      pendElemts;
  size_t pair = this->_sizeN / size;
  pendElemts.reserve(pair);
  size_t pending = size;

  for (size_t i = 1; i < pair; ++i) {
    size_t main = pending - size;
    pendElemts.push_back(std::make_pair(this->_vec.begin() + pending,
                                        this->_vec.begin() + main));
    pending += size * 2;
    if (pending + size > this->_sizeN) {
      if (pending <= this->_sizeN) {
        pendElemts.push_back(std::make_pair(
            this->_vec.begin() + (pending - size), this->_vec.end()));
      }
      break;
    }
  }
  return pendElemts;
}

void PmergeMe::printVectorTime() {
  double timeInMilliseconds = this->_vecSortTime / 1000.0;

  std::cout << "Time to process a range of " << this->_sizeN
            << " elements with std::vector : " << timeInMilliseconds << " ms"
            << std::endl;
}

void PmergeMe::printDequeTime() {
  double timeInMilliseconds = this->_deqSortTime / 1000.0;

  std::cout << "Time to process a range of " << this->_sizeN
            << " elements with std::deque : " << timeInMilliseconds << " ms"
            << std::endl;
}

void PmergeMe::setVectorSortTime() {
  struct timeval endTime;
  gettimeofday(&endTime, NULL);

  long secondsDiff = (endTime.tv_sec - this->_vecTime.tv_sec) * 1000000.0;

  long microSecondsDiff = (endTime.tv_usec - this->_vecTime.tv_usec);

  this->_vecSortTime = secondsDiff + microSecondsDiff;
}

void PmergeMe::setDequeSortTime() {
  struct timeval endTime;
  gettimeofday(&endTime, NULL);

  long secondsDiff = (endTime.tv_sec - this->_deqTime.tv_sec) * 1000000.0;

  long microSecondsDiff = (endTime.tv_usec - this->_deqTime.tv_usec);

  this->_deqSortTime = secondsDiff + microSecondsDiff;
}

void PmergeMe::isSortedVector() {
  for (size_t i = 0; i < this->_sizeN - 1; ++i) {
    if (this->_vec[i] > this->_vec[i + 1]) {
      std::cout << "false" << std::endl;
      return;
    }
  }
  std::cout << "true" << std::endl;
}

void PmergeMe::fordJohnsonAlgorithmDeque(size_t size) {
  size_t pair = this->_sizeN / size;

  this->pairSortDeque(size);
  if (pair == 1) {
    return;
  }
  this->fordJohnsonAlgorithmDeque(size * 2);

  this->mergeInsertionSortDeque(size);
}

void PmergeMe::pairSortDeque(size_t size) {
  if (size == 1) return;
  size_t pair = this->_sizeN / size;
  size_t range = size / 2;
  for (size_t i = 0; i < pair; ++i) {
    size_t first = i * size;
    size_t second = first + range;
    if (this->_deq[first] < this->_deq[second]) {
      std::swap_ranges(this->_deq.begin() + first,
                       this->_deq.begin() + first + range,
                       this->_deq.begin() + second);
    }
  }
}

void PmergeMe::mergeInsertionSortDeque(size_t size) {
  std::deque<std::deque<int>::iterator> mainChain =
      this->makeMainChainDeque(size);
  std::deque<std::pair<std::deque<int>::iterator, std::deque<int>::iterator> >
      pendElemts = this->makePendElemtsDeque(size);
  mainChain.insert(mainChain.begin(), pendElemts[0].first);
  pendElemts.erase(pendElemts.begin());

  this->mergeDeque(mainChain, pendElemts);
  this->syncDeque(size, mainChain);
}

void PmergeMe::mergeDeque(
    std::deque<std::deque<int>::iterator>& mainChain,
    std::deque<std::pair<std::deque<int>::iterator,
                         std::deque<int>::iterator> >& pendElemts) {
  size_t insertData = 0;
  size_t pendElemtsSize = pendElemts.size();

  for (size_t i = 1; insertData < pendElemtsSize; ++i) {
    size_t jacobs = this->getJacobsThalSequence(i) - 2;
    if (jacobs >= pendElemtsSize) jacobs = pendElemtsSize - 1;
    size_t endIdx = this->getJacobsThalSequence(i - 1);
    if (endIdx != 0) endIdx -= 1;

    for (; endIdx <= jacobs;) {
      std::deque<std::deque<int>::iterator>::iterator last = mainChain.end();
      if (pendElemts[jacobs].second != this->_deq.end())
        last = std::find(mainChain.begin(), mainChain.end(),
                         pendElemts[jacobs].second);
      std::deque<std::deque<int>::iterator>::iterator first = mainChain.begin();
      std::deque<std::deque<int>::iterator>::iterator target =
          std::upper_bound(first, last, pendElemts[jacobs].first, compareDeque);
      mainChain.insert(target, pendElemts[jacobs].first);
      insertData++;
      if (jacobs == endIdx) break;
      jacobs--;
    }
  }
}

void PmergeMe::syncDeque(size_t size,
                         std::deque<std::deque<int>::iterator>& mainChain) {
  std::deque<int> temp;
  size_t pair = this->_sizeN / size;

  for (size_t i = 0; i < mainChain.size(); ++i) {
    std::deque<int>::iterator target = mainChain[i];
    temp.insert(temp.end(), target, target + size);
  }
  temp.insert(temp.end(), this->_deq.begin() + (pair * size), this->_deq.end());
  this->_deq.swap(temp);
}

std::deque<std::deque<int>::iterator> PmergeMe::makeMainChainDeque(
    size_t size) {
  std::deque<std::deque<int>::iterator> mainChain;
  size_t pair = this->_sizeN / (size * 2);

  size_t target = 0;
  for (size_t i = 0; i < pair; ++i) {
    mainChain.push_back(this->_deq.begin() + target);
    target += size * 2;
  }
  return mainChain;
}

std::deque<std::pair<std::deque<int>::iterator, std::deque<int>::iterator> >
PmergeMe::makePendElemtsDeque(size_t size) {
  std::deque<std::pair<std::deque<int>::iterator, std::deque<int>::iterator> >
      pendElemts;
  size_t pair = this->_sizeN / size;
  size_t pending = size;

  for (size_t i = 1; i < pair; ++i) {
    size_t main = pending - size;
    pendElemts.push_back(std::make_pair(this->_deq.begin() + pending,
                                        this->_deq.begin() + main));
    pending += size * 2;
    if (pending + size > this->_sizeN) {
      if (pending <= this->_sizeN) {
        pendElemts.push_back(std::make_pair(
            this->_deq.begin() + (pending - size), this->_deq.end()));
      }
      break;
    }
  }
  return pendElemts;
}

void PmergeMe::isSortedDeque() {
  for (size_t i = 0; i < this->_sizeN - 1; ++i) {
    if (this->_deq[i] > this->_deq[i + 1]) {
      std::cout << "false" << std::endl;
      return;
    }
  }
  std::cout << "true" << std::endl;
}

void PmergeMe::displayResult() {
  this->printSort();
  this->printVectorTime();
  this->printDequeTime();
}

int PmergeMe::getJacobsThalSequence(size_t n) {
  return this->_jacobsThalSequence[n];
}

void PmergeMe::run() {
  this->printInput();

  gettimeofday(&_vecTime, NULL);
  this->fordJohnsonAlgorithmVector(1);
  this->setVectorSortTime();

  gettimeofday(&_deqTime, NULL);
  this->fordJohnsonAlgorithmDeque(1);
  this->setDequeSortTime();

  this->displayResult();
}
