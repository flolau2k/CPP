#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {}

std::pair<int, int> PmergeMe::make_pair(int n1, int n2) {
  if (n1 > n2)
    return std::pair<int, int>(n1, n2);
  else
    return std::pair<int, int>(n2, n1);
}
