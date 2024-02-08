#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <cmath>

template <class Container>
class PmergeMe {
public:
  static void sort(Container &container);
  static void print(Container &container, size_t max_len);

private:
  PmergeMe();
  ~PmergeMe();

  void calculate_jacobsthal(int len);
  int divide(Container &container, int l, int r);
  void quicksort(Container &container, int l, int r);
  void swap(int &a, int &b);

  Container pending_chain;
  Container _jacobsthal;
  // std::multiset<std::pair<int, int> > _set;

  int _leftover;
  bool _leftover_set;
};

#include "PmergeMe.tpp"

#endif // PMERGEME_HPP
