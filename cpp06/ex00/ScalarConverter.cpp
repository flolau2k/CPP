#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

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

void print_type(type_t &type) {
  std::cout << "type is: ";
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
    case S_FLOAT:
      std::cout << "FLOAT!";
      break;
    case DOUBLE:
      std::cout << "DOUBLE!";
      break;
    case S_DOUBLE:
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

void print_as_char(std::istringstream &iss, type_t &t) {
  std::cout << "char: ";
  if (t == S_DOUBLE || t == S_FLOAT) {
    std::cout << "impossible" << std::endl;
    return;
  }
  reset_stream(iss);
  int c;
  iss >> c;
  if (std::isprint(c))
    std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
}

void print_as_int(std::istringstream &iss, type_t &t) {
  std::cout << "int: ";
  if (t == S_DOUBLE || t == S_FLOAT) {
    std::cout << "impossible" << std::endl;
    return;
  }
  reset_stream(iss);
  int c;
  iss >> c;
  std::cout << c << std::endl;
}

void print_as_float(std::istringstream &iss, type_t &t) {
  std::cout << "float: ";
  if (t == S_FLOAT) {std::cout << iss.str() << std::endl; return;}
  else if (t == S_DOUBLE) {std::cout << iss.str() << "f" << std::endl; return;}
  reset_stream(iss);
  float f;
  iss >> f;
  std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void print_as_double(std::istringstream &iss, type_t &t) {
  std::cout << "double: ";
  if (t == S_FLOAT) {
    std::string s = iss.str();
    s = s.substr(0, s.length() - 1);
    std::cout << s << std::endl;
    return;
  }
  else if (t == S_DOUBLE) {std::cout << iss.str() << std::endl; return;}
  reset_stream(iss);
  double d;
  iss >> d;
  std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string &s) {
  // std::cout << "original input: '" << s << "'\n";
  type_t type;
  try {
    type = check_special(s);
  } catch (const ScalarConverter::NotSpecialTypeException &e) {
    type = get_type(s);
  }
  // print_type(type);

  std::istringstream iss(s);

  print_as_char(iss, type);
  print_as_int(iss, type);
  print_as_float(iss, type);
  print_as_double(iss, type);

}
