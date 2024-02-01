#include <sys/time.h>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error: No Args given!" << std::endl;
    return 1;
  }
  
  std::vector<int> vec;
  std::deque<int> deq;
  int val;

  for (int i = 1; i < argc; ++i) {
    std::istringstream iss(argv[i]);
    iss >> val;
    if (iss.fail()) {
      std::cerr << "Error" << std::endl;
      return 1;
    }
    vec.push_back(val);
    deq.push_back(val);
  }

  
  
}