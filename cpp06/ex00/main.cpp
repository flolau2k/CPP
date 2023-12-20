#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Error: no input!" << std::endl;
    return 1;
  }
  std::string param(argv[1]);
  type_t type = ScalarConverter::get_type(param);
  switch (type) {
    case CHAR:
      std::cout << "Char!" << std::endl;
      break;
    case INT:
      std::cout << "Integer!" << std::endl;
      break;
    case FLOAT:
      std::cout << "Float!" << std::endl;
      break;
    case DOUBLE:
      std::cout << "Double!" << std::endl;
      break;
    case ERROR:
      std::cout << "Error!" << std::endl;
  }
  return 0;
}
