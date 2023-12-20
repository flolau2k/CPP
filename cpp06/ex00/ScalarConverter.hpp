#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum type_t {CHAR, INT, FLOAT, DOUBLE, ERROR};

class ScalarConverter {
public:
  static void convert(const std::string &param);
  static type_t get_type(const std::string &s);

private:

  static bool is_char(const std::string &s);
  static bool is_int(const std::string &s);
  static bool is_float(const std::string &s);
  static bool is_double(const std::string &s);
  ScalarConverter();
  ScalarConverter(const ScalarConverter &cpy);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();
};

#endif // SCALARCONVERTER_HPP