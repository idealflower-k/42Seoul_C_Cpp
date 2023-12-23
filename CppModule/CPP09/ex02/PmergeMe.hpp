#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#define ERROR "ERROR"

class PmergeMe {
 private:
  std::vector<int> _jacobsThalSequence;
  std::vector<int> _vec;
  std::deque<int> _deq;
  size_t _sizeN;
  struct timeval _vecTime;
  long _vecSortTime;
  struct timeval _deqTime;
  long _deqSortTime;

  PmergeMe();
  PmergeMe(const PmergeMe& pmergeMe);
  PmergeMe& operator=(const PmergeMe& pmergeMe);

  void setJacobsThalSequence();
  void initData(char** av);
  bool validData(std::string data);
  int strToInt(std::string str);

  void fordJohnsonAlgorithmVector(size_t size);
  void pairSortVector(size_t size);
  void mergeInsertionSortVector(size_t size);
  std::vector<std::vector<int>::iterator> makeMainChainVector(size_t size);
  std::vector<
      std::pair<std::vector<int>::iterator, std::vector<int>::iterator> >
  makePendElemtsVector(size_t size);
  void mergeVector(
      std::vector<std::vector<int>::iterator>& mainChain,
      std::vector<std::pair<std::vector<int>::iterator,
                            std::vector<int>::iterator> >& pendElemts);
  void syncVector(size_t size,
                  std::vector<std::vector<int>::iterator>& mainChain);
  void printVector();
  void setVectorSortTime();
  void printVectorTime();

  void fordJohnsonAlgorithmDeque(size_t size);
  void pairSortDeque(size_t size);
  void mergeInsertionSortDeque(size_t size);
  std::deque<std::deque<int>::iterator> makeMainChainDeque(size_t size);
  std::deque<std::pair<std::deque<int>::iterator, std::deque<int>::iterator> >
  makePendElemtsDeque(size_t size);
  void mergeDeque(
      std::deque<std::deque<int>::iterator>& mainChain,
      std::deque<std::pair<std::deque<int>::iterator,
                           std::deque<int>::iterator> >& pendElemts);
  void syncDeque(size_t size, std::deque<std::deque<int>::iterator>& mainChain);
  void printDeque();
  void setDequeSortTime();
  void printDequeTime();

  int getJacobsThalSequence(size_t n);
  void printInput();
  void printSort();

  void isSortedVector();
  void isSortedDeque();
  void displayResult();

 public:
  PmergeMe(char** av);
  ~PmergeMe();

  void run();
};

#endif
