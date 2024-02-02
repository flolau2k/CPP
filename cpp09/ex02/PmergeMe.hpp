#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>

class PmergeMe {
public:

  template <typename iter>
  static void recursive_sort(iter begin, iter _end) {
    iter end = _end;
    std::cout << "begin : end = " << *begin << " : " << *end << std::endl;
    int distance = std::distance(begin, end);
    std::cout << "distance: " << distance << std::endl;
    // need to do this only on the first occurence.
    if (distance % 2 == 0) {
      --end;
    }
    switch (distance) {
      case 1:
        std::cout << "2 elm: " << *begin << " : " << *end << std::endl;
        if (*begin > *end) std::swap(*begin, *end);
        // if (*begin > *end) std::cout << "would swap..." << std::endl;
        // fallthrough
      case 0:
        std::cout << "return" << std::endl;
        return;
      // case 2:
      //   std::cout << "dist 2" << std::endl;

      default:
        std::cout << "recursion ... " << std::endl;
        recursive_sort(begin, begin + distance / 2);
        recursive_sort(begin + distance / 2 , end);
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