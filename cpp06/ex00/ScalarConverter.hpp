#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
  static void convert(const std::string &param);

private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &cpy);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();
};

#endif // SCALARCONVERTER_HPP