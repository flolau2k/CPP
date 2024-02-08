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

  std::cout << "before:\t";
  PmergeMe<std::vector<int> >::print(vec);
  // timer
  clock_t t_vec = clock();
  // vec
  vec = PmergeMe<std::vector<int> >::sort(vec);
  // vec time
  t_vec = clock() - t_vec;
  std::cout << "after:\t";
  PmergeMe<std::vector<int> >::print(vec);

  //timer
  clock_t t_deq = clock();
  // deq
  PmergeMe<std::deque<int> >::sort(deq);
  // deq time
  t_deq = clock() - t_deq;
  // PmergeMe::print(deq);
  std::cout << "time elapsed with std::vector: " << t_vec << std::endl;
  std::cout << "time elapsed with std::deque: " << t_deq << std::endl;
  
  return 0;
}
