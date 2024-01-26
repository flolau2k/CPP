#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Error: wrong number of input args!" << std::endl;
    return 1;
  }
  std::string param(argv[1]);
  ScalarConverter::convert(param);
  return 0;
}
