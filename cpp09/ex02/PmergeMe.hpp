#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <cmath>

class PmergeMe {
public:
  static std::pair<int, int> make_pair(int n1, int n2);

  void calculate_jacobsthal(int len) {
    _jacobsthal.push_back(1);
    while (_jacobsthal.back() < (len / 2) + 1) {
      int len = _jacobsthal.size() + 1;
      double curr_val = (std::pow(2, len + 1) + std::pow(-1, len)) / 3;
      _jacobsthal.push_back(static_cast<int>(curr_val));
    }
  }

  static std::vector<int> sort(std::vector<int> &container) {
    typedef std::vector<int>::iterator iter;
    PmergeMe pm;
    pm.calculate_jacobsthal(container.size());

    // std::cout << "jacobsthal sequence: " << std::endl;
    // for (std::vector<int>::iterator it = pm._jacobsthal.begin(); it != pm._jacobsthal.end(); it++){
    //   std::cout << *it << " ";
    // }
    // std::cout << std::endl;

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

    int id = 1;
    typedef std::set<std::pair<int, int> >::iterator siter;
    for (siter it = pm._set.begin(); it != pm._set.end(); it++) {
      // pm.main_chain.push_back(std::pair<int, int>(id, it->first));
      // pm.pending_chain.push_back(std::pair<int, int>(id, it->second));
      pm.main_chain.push_back(it->first);
      pm.pending_chain.push_back(it->second);
      ++id;
    }
    if (pm._leftover_set) {
      pm.pending_chain.push_back(pm._leftover);
    }
    // pm.main_chain.insert(pm.main_chain.begin(), pm.pending_chain[0]);
    id = 0;
    for (iter it = pm._jacobsthal.begin(); it != pm._jacobsthal.end(); it++) {
        // reverse from jacobsthal number to last insert
        for (int j = *it; j > id; --j) {
          iter first = pm.main_chain.begin();
          iter last = pm.main_chain.end();
          int curr_val;
          try {
            curr_val = pm.pending_chain.at(j - 1); // start counting at 1
          } catch (const std::out_of_range &) {
            continue;
          }
          iter pos = std::lower_bound(first, last, curr_val);
          pm.main_chain.insert(pos, curr_val);
        }
        id = *it;
    }
    return pm.main_chain;
  }

  template <class IterableContainer>
  static void print(IterableContainer &container) {
    typedef typename IterableContainer::iterator iter;
    for (iter it = container.begin(); it != container.end(); ++it) {
      std::cout << *it << std::endl;
    }
  }

private:
  PmergeMe();
  ~PmergeMe();

  std::vector<int> main_chain;
  std::vector<int> pending_chain;

  std::vector<int> _jacobsthal;

  std::set<std::pair<int, int> > _set;
  int _leftover;
  bool _leftover_set;
};

#endif // PMERGEME_HPP
