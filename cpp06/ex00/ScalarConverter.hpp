#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter {
public:
  static void convert(const std::string &param) const;

private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &cpy);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();
};

#endif // SCALARCONVERTER_HPP