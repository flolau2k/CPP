#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Invalid Number of Args!" << std::endl;
    return 1;
  }

  std::cout << argv[1] << std::endl;
  return 0;
}