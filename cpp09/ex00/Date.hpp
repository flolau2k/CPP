#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Date {
public:
  Date(const std::string &date_s = "1970-01-01");
  Date(const Date &cpy);
  Date &operator=(const Date &other);
  ~Date();

  bool validate() const;

  class InvalidDateException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  int _year;
  int _month;
  int _day;

};

#endif // DATE_HPP