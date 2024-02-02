#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <time.h>
#include <unistd.h>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error: No Args given!" << std::endl;
    return 1;
  }
  
  std::vector<int> vec;
  std::deque<int> deq;

  for (int i = 1; i < argc; ++i) {
    std::istringstream iss(argv[i]);
    int val;
    iss >> val;
    if (iss.fail()) {
      std::cerr << "Error" << std::endl;
      return 1;
    }
    vec.push_back(val);
    deq.push_back(val);
  }

  // timer
  clock_t t = clock();
  // vec
  PmergeMe::recursive_sort(vec.begin(), vec.end() - 1);
  // vec time
  t = clock() - t;
  std::cout << "time elapsed: " << t << std::endl;
  PmergeMe::print(vec);

  // timer
  t = clock();
  // deq
  PmergeMe::recursive_sort(deq.begin(), deq.end() - 1);
  // deq time
  t = clock() - t;
  std::cout << "time elapsed: " << t << std::endl;
  PmergeMe::print(deq);
  
  return 0;
}