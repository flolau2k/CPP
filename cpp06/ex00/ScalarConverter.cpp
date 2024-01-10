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

void check_stream(std::istringstream &iss) {
  if (iss.good()) std::cout << "string good!" << std::endl;
  else if (iss.eof()) std::cout << "string eof!" << std::endl;
  else if (iss.fail()) std::cout << "string fail!" << std::endl;
  else if (iss.bad()) std::cout << "string bad!" << std::endl;
}

void print_type(type_t &type) {
  switch (type) {
    case CHAR:
      std::cout << "CHAR!";
      break;
    case INT:
      std::cout << "INT!";
      break;
    case FLOAT:
      std::cout << "FLOAT!";
      break;
    case DOUBLE:
      std::cout << "DOUBLE!";
      break;
    default:
      std::cout << "ERROR TYPE!";
  }
  std::cout << std::endl;
}

void reset_stream(std::istringstream &iss) {
  iss.clear();
  iss.seekg(0, std::ios::beg);
}

void ScalarConverter::convert(const std::string &s) {
  std::cout << "original input: '" << s << "'\n";
  type_t type;
  try {
    type = check_special(s);
  } catch (const ScalarConverter::NotSpecialTypeException &e) {
    type = get_type(s);
  }
  print_type(type);
  std::istringstream ss(s);
  double d;
  int i;
  float f;
  char c;

  ss >> d;
  reset_stream(ss);
  std::cout << "double: " << d << "\n";
  ss >> i;
  reset_stream(ss);
  std::cout << "int: " << i << "\n";
  ss >> f;
  reset_stream(ss);
  std::cout << "float: " << f << "\n";
  ss >> c;
  reset_stream(ss);
  std::cout << "char: " << c << std::endl;

}
