#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

const char *ScalarConverter::NotSpecialTypeException::what() const throw() {
  return "Input is not of special Type!";
}

type_t ScalarConverter::check_special(const std::string &s) {
  static const std::string specials_float[] = {"-inff", "+inff", "nanf"};
  static const std::string specials_double[] = {"-inf", "+inf", "nan"};
  for (int i = 0; i < 3; ++i) {
    if (s == specials_float[i])
      return S_FLOAT;
  }
  for (int i = 0; i < 3; ++i) {
    if (s == specials_double[i])
      return S_DOUBLE;
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
    if (i == 0 && (s[i] == '+' || s[i] == '-'))
      continue;
    else if (i == len - 1 && s[i] == 'f')
      return FLOAT;
    else if (s[i] == '.') {
      if (dec)
        return ERROR;
      dec = true;
    } 
    else if (!std::isdigit(s[i]))
      return ERROR;
  }
  if (dec)
    return DOUBLE;
  return INT;
}

void ScalarConverter::handle_char(const std::string &s) {
  std::istringstream iss(s);
  char    c;
  long    i;
  float   f;
  double  d;
  iss >> c;
  i = static_cast<int>(c);
  f = static_cast<float>(c);
  d = static_cast<double>(c);
  std::cout << "char: '" << c << "'\n"
    << "int: " << i << "\n"
    << "float: " << f << "f\n"
    << "double: " << d << std::endl;
}

void ScalarConverter::handle_int(const std::string &s) {
  std::istringstream iss(s);
  char    c;
  long    i;
  float   f;
  double  d;
  iss >> i;
  c = static_cast<char>(i);
  f = static_cast<float>(i);
  d = static_cast<double>(i);
  if (i >= 0 && std::isprint(i))
    std::cout << "char: '" << c << "'\n";
  else
    std::cout << "char: Non displayable\n";
  if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
    std::cout << "int: overflow\n";
  else
    std::cout << "int: " << i << "\n";
  std::cout << "float: " << f << "f\n"
    << "double: " << d << std::endl;
}

void ScalarConverter::handle_float(const std::string &s) {
  std::istringstream iss(s.substr(0, s.length() - 1));
  char    c;
  long    i;
  float   f;
  double  d;
  iss >> f;
  c = static_cast<char>(f);
  i = static_cast<int>(f);
  d = static_cast<double>(f);
  if (i >= 0 && std::isprint(i))
    std::cout << "char: '" << c << "'\n";
  else
    std::cout << "char: Non displayable\n";
  std::cout << "int: " << i << "\n"
    << "float: " << f << "f\n"
    << "double: " << d << std::endl;
}

void ScalarConverter::handle_double(const std::string &s) {
  std::istringstream iss(s);
  char    c;
  long    i;
  float   f;
  double  d;
  iss >> d;
  c = static_cast<char>(d);
  i = static_cast<int>(d);
  f = static_cast<float>(d);
  if (i >= 0 && std::isprint(i))
    std::cout << "char: '" << c << "'\n";
  else
    std::cout << "char: Non displayable\n";
  std::cout << "int: " << i << "\n"
    << "float: " << f << "f\n"
    << "double: " << d << std::endl;
}

void ScalarConverter::handle_type(type_t &type, const std::string &s) {
  std::string ns;
  switch (type) {
    case CHAR:
      handle_char(s);
      break;
    case INT:
      // std::cout << "INT!" << std::endl;
      handle_int(s);
      break;
    case FLOAT:
      handle_float(s);
      break;
    case S_FLOAT:
      // std::cout << "S_FLOAT!" << std::endl;
      ns = s.substr(0, s.length() - 1);
      std::cout << "char: impossible\n"
        << "int: impossible\n"
        << "float: " << s << "\n"
        << "double: " << ns << std::endl;
      break;
    case DOUBLE:
      handle_double(s);
      break;
    case S_DOUBLE:
      // std::cout << "S_DOUBLE!" << std::endl;
      std::cout << "char: impossible\n"
        << "int: impossible\n"
        << "float: " << s << "f\n"
        << "double: " << s << std::endl;
      break;
    default:
      std::cout << "ERROR TYPE!" << std::endl;
  }
}

void ScalarConverter::convert(const std::string &s) {
  // std::cout << "original input: '" << s << "'\n";
  type_t type;
  try {
    type = check_special(s);
  } catch (const ScalarConverter::NotSpecialTypeException &e) {
    type = get_type(s);
  }
  handle_type(type, s);
}
