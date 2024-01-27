#include "Date.hpp"
#include <iostream>
#include <sstream>

int Date::to_int(const std::string &arg) const {
  std::istringstream iss(arg);
  int val;
  iss >> val;
  if (iss.fail())
    throw InvalidDateException();
  return val;
}

Date::Date(const std::string &date_s /*= "1970-01-01"*/) {
  int count = 0;
  std::string curr_val;
  std::istringstream iss(date_s);
  while (std::getline(iss, curr_val, '-')) {
    switch (count) {
    case 0:
      _year = to_int(curr_val);
      break;
    case 1:
      _month = to_int(curr_val);
      break;
    case 2:
      _day = to_int(curr_val);
      break;
    default:
      throw InvalidDateException();
    }
    ++count;
  }
  if (!validate())
    throw InvalidDateException();
}

Date::Date(const Date &cpy) { *this = cpy; }

Date::~Date() {}

Date &Date::operator=(const Date &other) {
  if (this != &other) {
    _year = other._year;
    _month = other._month;
    _day = other._day;
  }
  return *this;
}

const char *Date::InvalidDateException::what() const throw() {
  return "Date is invalid!";
}

bool Date::check_leap_year() const {
  if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
    return true;
  else
    return false;
}

bool Date::validate() const {
  if (_year < 0 || _year > 2100)
    return false;
  if (_month < 1 || _month > 12)
    return false;
  int month = 1 << (_month - 1);
  if (_month == 2) {
    if (check_leap_year()) {
      if (_day < 1 || _day > 29)
        return false;
    } else {
      if (_day < 1 || _day > 28)
        return false;
    }
  } else if (month & _30dayMonths) {
    if (_day > 30 || _day < 1)
      return false;
  } else {
    if (_day > 31 || _day < 1)
      return false;
  }
  return true;
}

bool Date::operator<(const Date &date) const {
  if (_year < date._year) return true;
  else if (_year > date._year) return false;
  if (_month < date._month) return true;
  else if (_month > date._month) return false;
  if (_day < date._day) return true;
  return false;
}

bool Date::operator>(const Date &date) const {
  return date < *this;
}

bool Date::operator<=(const Date &date) const {
  return !(*this > date);
}

bool Date::operator>=(const Date &date) const {
  return !(*this < date);
}

bool Date::operator==(const Date &date) const {
  if (_year == date._year && _month == date._month && _day == date._day)
    return true;
  return false;
}

bool Date::operator!=(const Date &date) const {
  return !(*this == date);
}

int Date::get_day() const {
  return _day;
}

int Date::get_month() const {
  return _month;
}

int Date::get_year() const {
  return _year;
}

std::ostream &operator<<(std::ostream &out, const Date &date) {
  return out << date.get_year() << "-" << date.get_month() << "-"
            << date.get_day();
}
