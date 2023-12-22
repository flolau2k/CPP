#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>

const char *ScalarConverter::NotSpecialTypeException::what() const throw() {
  return "Input is not of special Type!";
}

type_t ScalarConverter::check_special(const std::string &s) {
  static const std::string specials_float[] = {"-inff", "+inff", "nanf"};
  static const std::string specials_double[] = {"-inf", "+inf", "nan"};
  for (int i = 0; i < 3; ++i) {
    if (s == specials_float[i])
      return FLOAT;
  }
  for (int i = 0; i < 3; ++i) {
    if (s == specials_double[i])
      return DOUBLE;
  }
  throw NotSpecialTypeException();
}

type_t ScalarConverter::get_type(const std::string &s) {
  if (s.length() == 1) {
    if (std::isdigit(s[0]))
      return INT;
    return CHAR;
  }
  bool dec = false;
  int len = s.length();
  for (int i = 0; i < len; ++i) {
    if (i == len - 1 && s[i] == 'f')
      return FLOAT;
    if (s[i] == '.') {
      if (dec)
        return ERROR;
      dec = true;
    } else if (!std::isdigit(s[i]))
      return ERROR;
  }
  if (dec)
    return DOUBLE;
  return INT;
}

void ScalarConverter::convert(const std::string &s) {
  std::cout << "original input: '" << s << "'\n";
  type_t type;
  try {
    type = check_special(s);
  } catch (const ScalarConverter::NotSpecialTypeException &e) {
    type = get_type(s);
  }
  std::stringstream ss;
  double d;
  ss << s;
  ss >> d;
  int i;
  ss << s;
  ss >> i;
  float f;
  ss << s;
  ss >> f;
  char c;
  ss << s;
  ss >> c;

  switch (type) {
  case CHAR:
    std::cout << "as int: " << i << "\n"
              << "as float: " << f << "\n"
              << "as double: " << d << std::endl;
    break;
  case INT:
    std::cout << "as char: " << static_cast<int>(c) << "\n"
              << "as float: " << f << "\n"
              << "as double: " << d << std::endl;
    break;
  case FLOAT:
    std::cout << "FLOAT!" << std::endl;
    break;
  case DOUBLE:
    std::cout << "DOUBLE!" << std::endl;
    break;
  default:
    std::cout << "ERROR!" << std::endl;
    break;
  }
}
