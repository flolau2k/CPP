#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include "time.h"

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
  size_t start = get_microseconds();
  // vector
  usleep(10);
  // vec time
  std::cout << "time elapsed: " << (get_microseconds() - start) << std::endl;

  // timer
  // deq
  // deq time
  
  return 0;
}