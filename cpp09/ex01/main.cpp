#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Invalid Number of Args!" << std::endl;
    return 1;
  }

  try {
    std::cout << RPN::calculate(argv[1]) << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Error" << std::endl;
  }
  return 0;
}
