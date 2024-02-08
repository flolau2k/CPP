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
  static Container sort(Container &container);

  static void print(Container &container);

private:
  PmergeMe();
  ~PmergeMe();

  void calculate_jacobsthal(int len);
  static std::pair<int, int> make_pair(int n1, int n2);

  Container main_chain;
  Container pending_chain;
  Container _jacobsthal;
  std::multiset<std::pair<int, int> > _set;

  int _leftover;
  bool _leftover_set;
};

#include "PmergeMe.tpp"

#endif // PMERGEME_HPP
