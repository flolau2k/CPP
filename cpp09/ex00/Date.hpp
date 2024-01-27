#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Date {
public:
  Date(const std::string &date_s = "1970-01-01");
  Date(const Date &cpy);
  Date &operator=(const Date &other);
  ~Date();

  bool operator>(const Date &date) const;
  bool operator<(const Date &date) const;
  bool operator>=(const Date &date) const;
  bool operator<=(const Date &date) const;
  bool operator==(const Date &date) const;
  bool operator!=(const Date &date) const;

  bool validate() const;

  class InvalidDateException : public std::exception {
  public:
    const char *what() const throw();
  };

  int get_year() const;
  int get_month() const;
  int get_day() const;

private:
  int _year;
  int _month;
  int _day;

  static const int _30dayMonths = (1 << 3) | (1 << 5) | (1 << 8) | (1 << 10);
  int to_int(const std::string &arg) const;
  bool check_leap_year() const;
};

std::ostream &operator<<(std::ostream &out, const Date &date);

#endif // DATE_HPP