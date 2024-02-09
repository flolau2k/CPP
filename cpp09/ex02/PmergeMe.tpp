#include <cmath>
#include "PmergeMe.hpp"

template <class Container>
PmergeMe<Container>::PmergeMe() {}

template <class Container>
PmergeMe<Container>::~PmergeMe() {}

template <class Container>
void PmergeMe<Container>::calculate_jacobsthal(int len) {
  _jacobsthal.push_back(1);
  while (_jacobsthal.back() < (len / 2) + 1) {
    int len = _jacobsthal.size() + 1;
    double curr_val = (std::pow(2, len + 1) + std::pow(-1, len)) / 3;
    _jacobsthal.push_back(static_cast<int>(curr_val));
  }
}

template <class Container>
void PmergeMe<Container>::swap(int &a, int &b) {
  int val = a;
  a = b;
  b = val;
}

template <class Container>
int PmergeMe<Container>::divide(Container &container, int l, int r) {
  int i, j, pivot;

  i = l;
  j = r - 1;
  pivot = container[r];
  while (i < j) {
    while (i < j && container[i] <= pivot)
      ++i;
    while (j > i && container[j] > pivot)
      --j;
    if (container[i] > container[j]){
      swap(container[i], container[j]);
      swap(pending_chain[i], pending_chain[j]);
    }
  }
  if (container[i] > pivot) {
    swap(container[i], container[r]);
    swap(pending_chain[i], pending_chain[r]);
  } else
    i = r;
  return i;
}

template <class Container>
void PmergeMe<Container>::quicksort(Container &container, int l, int r) {
  size_t pivot;
  if (l < r) {
    pivot = divide(container, l, r);
    quicksort(container, l, pivot - 1);
    quicksort(container, pivot + 1, r);
  }
}

template <class Container>
void PmergeMe<Container>::sort(Container &container) {
  typedef typename Container::iterator iter;
  PmergeMe<Container> pm;
  pm.calculate_jacobsthal(container.size());
  pm._leftover_set = false;
  size_t curr_size = container.size();
  for (size_t i = 0; i < curr_size; ++i) {
    if (i + 1 >= curr_size) {
      pm.pending_chain.push_back(container[i]);
      container.pop_back();
      break;
    }
    if (container[i] > container[i + 1]) {
      pm.pending_chain.push_back(container[i + 1]);
      container.erase(container.begin() + i + 1);
    } else {
      pm.pending_chain.push_back(container[i]);
      container.erase(container.begin() + i);
    }
    curr_size = container.size();
  }

  // sort the main chain and mirror the movements in the pending chain
  pm.quicksort(container, 0, container.size() - 1);

  int id = 0;
  for (iter it = pm._jacobsthal.begin(); it != pm._jacobsthal.end(); it++) {
    // reverse from jacobsthal number to last insert
    for (int j = *it; j > id; --j) {
      iter first = container.begin();
      iter last = container.end();
      int curr_val;
      try {
        curr_val = pm.pending_chain.at(j - 1); // start counting at 1
      } catch (const std::out_of_range &) {
        continue;
      }
      iter pos = std::lower_bound(first, last, curr_val);
      container.insert(pos, curr_val);
    }
    id = *it;
  }
}

template <class Container>
void PmergeMe<Container>::print(Container &container, size_t max_len) {
  size_t len = std::min(container.size(), max_len);
  for (size_t i = 0; i < len; i++) {
    std::cout << container.at(i) << " ";
  }
  if (container.size() > max_len)
    std::cout << "[...]";
  std::cout << std::endl;
}
