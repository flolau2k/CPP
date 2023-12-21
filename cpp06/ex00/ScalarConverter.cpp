#include <sstream>
#include <iostream>
#include "ScalarConverter.hpp"

bool ScalarConverter::is_char(const std::string &s) {
  char c;
  std::stringstream ss(s);
  if (ss >> c) return true;
  return false;
}

bool ScalarConverter::is_int(const std::string &s) {
  int i;
  std::stringstream ss(s);
  if (ss >> i) return true;
  return false;
}

bool ScalarConverter::is_float(const std::string &s) {
  float f;
  std::stringstream ss(s);
  if (ss >> f) return true;
  return false;
}

bool ScalarConverter::is_double(const std::string &s) {
  double d;
  std::stringstream ss(s);
  if (ss >> d) return true;
  return false;
}

type_t ScalarConverter::get_type(const std::string &s) {
  char c;
  int i;
  float f;
  double d;
  std::stringstream ss(s);
  if (ss >> c) return CHAR;
  if (ss >> i) return INT;
  if (ss >> f) return FLOAT;
  if (ss >> d) return DOUBLE;
  return ERROR;
}

void ScalarConverter::convert(const std::string &s) {
  std::cout << "original input: '" << s << "'\n";
  if (is_char(s)) std::cout << "is a char.";
}
