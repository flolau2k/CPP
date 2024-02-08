#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <set>
#include <utility>

class PmergeMe {
public:
  static std::pair<int, int> make_pair(int n1, int n2);

  void calculate_jacobsthal(size_t len) {
    for (int i = 0; i <= )
  }

  static void sort(std::vector<int> &container) {
    typedef std::vector<int>::iterator iter;
    PmergeMe pm;
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
      pm.main_chain.push_back(std::pair<int, int>(id, it->first));
      pm.pending_chain.push_back(std::pair<int, int>(id, it->second));
      ++id;
    }
    if (pm._leftover_set) {
      pm.pending_chain.push_back(std::pair<int, int>(id, pm._leftover));
    }

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

  std::vector<std::pair<int, int> > main_chain;
  std::vector<std::pair<int, int> > pending_chain;

  std::vector<int> _jacobsthal;

  std::set<std::pair<int, int> > _set;
  int _leftover;
  bool _leftover_set;
};

#endif // PMERGEME_HPP
