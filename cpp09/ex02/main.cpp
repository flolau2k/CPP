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
    if (iss.fail() || val < 0) {
      std::cerr << "Error" << std::endl;
      return 1;
    }
    vec.push_back(val);
    deq.push_back(val);
  }

  std::cout << "before:\t";
  PmergeMe<std::vector<int> >::print(vec, 10);

  clock_t t_vec = clock();
  PmergeMe<std::vector<int> >::sort(vec);
  t_vec = clock() - t_vec;

  clock_t t_deq = clock();
  PmergeMe<std::deque<int> >::sort(deq);
  t_deq = clock() - t_deq;

  size_t len = vec.size();
  if (len != deq.size()) {
    std::cerr << "error!" << std::endl;
    return 1;
  }

  for (size_t i = 0; i < len; ++i) {
    if (vec.at(i) != deq.at(i)) {
      std::cerr << "error!" << std::endl;
      return 1;
    }
  }

  std::cout << "after:\t";
  PmergeMe<std::vector<int> >::print(vec, 10);

  std::cout << "time elapsed with std::vector: " << t_vec << std::endl;
  std::cout << "time elapsed with std::deque: " << t_deq << std::endl;
  
  return 0;
}
