#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>

class PmergeMe {
public:

  template <typename iter>
  static void recursive_sort(iter begin, iter end) {
    int distance = std::distance(begin, end) == 1;
    switch (distance) {
      case 1:
        if (*begin > *end) std::swap(*begin, *end);
        // fallthrough
      case 0:
        return;
      default:
        recursive_sort(begin, begin + std::distance(begin, end) / 2);
        recursive_sort(begin + std::distance(begin, end) / 2, end);
    }
  }

  template <class IterableContainer>
  static void sort(IterableContainer &container) {
    typedef typename IterableContainer::iterator iter;
    
    // make pairs and sort them.
    for (iter it = container.begin(); it != container.end(); ++it) {
      iter it_2 = it + 1;
      if (it_2 == container.end())
        continue;
      if (*it > *it_2) {
        std::swap(*it, *it_2);
      } 
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
  PmergeMe() {}
  ~PmergeMe() {}

};

#endif // PMERGEME_HPP