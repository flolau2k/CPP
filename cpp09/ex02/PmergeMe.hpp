#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <set>
#include <utility>

class PmergeMe {
public:

  static std::pair<int, int> make_pair(int n1, int n2);

  template <class IterableContainer>
  static void sort(IterableContainer &container) {
    typedef typename IterableContainer::iterator iter;
    
    // make pairs and sort them in a std::set.
    PmergeMe pm;

    for (iter it = container.begin(); it != container.end(); it+=2) {
      iter it_2 = it + 1;
      if (it_2 == container.end()) {
        pm._leftover = *it;
        pm._leftover_set = true;
        break;
      }
      pm._set.insert(make_pair(*it, *it_2));
    }
    for (std::set<std::pair<int, int> >::iterator it = pm._set.begin(); it != pm._set.end(); ++it) {
      std::cout << "current pair: " << it->first << ", " << it->second << std::endl;
    }
    if (pm._leftover_set) {
      std::cout << "_leftover: " << pm._leftover << std::endl;
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

  std::set<std::pair<int, int> > _set;
  int _leftover;
  bool _leftover_set;
};

#endif // PMERGEME_HPP
