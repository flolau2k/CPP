#include "PmergeMe.hpp"

template <class Container>
PmergeMe<Container>::PmergeMe() {}

template <class Container>
PmergeMe<Container>::~PmergeMe() {}

template <class Container>
std::pair<int, int> PmergeMe<Container>::make_pair(int n1, int n2) {
  if (n1 > n2)
    return std::pair<int, int>(n1, n2);
  else
    return std::pair<int, int>(n2, n1);
}

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
void PmergeMe<Container>::sort(Container &container) {
  typedef typename Container::iterator iter;
  PmergeMe<Container> pm;
  pm.calculate_jacobsthal(container.size());

  pm._leftover_set = false;
  for (iter it = container.begin(); it != container.end(); it+=2) {
    iter it_2 = it + 1;
    if (it_2 == container.end()) {
      pm._leftover = *it;
      pm._leftover_set = true;
      break;
    }
    pm._set.insert(make_pair(*it, *it_2));
  }

  // clear the input container to use as new main chain.
  container.clear(); 
  int id = 1;
  typedef std::set<std::pair<int, int> >::iterator siter;
  for (siter it = pm._set.begin(); it != pm._set.end(); it++) {
    container.push_back(it->first);
    pm.pending_chain.push_back(it->second);
    ++id;
  }
  if (pm._leftover_set) {
    pm.pending_chain.push_back(pm._leftover);
  }
  id = 0;
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
