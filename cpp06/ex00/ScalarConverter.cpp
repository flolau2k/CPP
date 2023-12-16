#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &param) {
  std::cout << "original string input: " << param << "\n";
  std::cout << "as char: " << std::atoi(param.c_str()) << "\n";
  std::cout << "as int: " << std::atoi(param.c_str());
}
