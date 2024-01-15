#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum type_t {CHAR, INT, FLOAT, S_FLOAT, DOUBLE, S_DOUBLE, ERROR};

class ScalarConverter {
public:
  static void convert(const std::string &param);

private:
  static type_t get_type(const std::string &s);
  static type_t check_special(const std::string &s);
  static void handle_char(const std::string &s);
  static void handle_int(const std::string &s);
  static void handle_float(const std::string &s);  
  static void handle_double(const std::string &s);
  static void handle_type(type_t &type, const std::string &s);

  class NotSpecialTypeException : public std::exception {
  public:
    const char *what() const throw();
  };

  ScalarConverter();
  ScalarConverter(const ScalarConverter &cpy);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();
};

#endif // SCALARCONVERTER_HPP