#include "Date.hpp"
#include <sstream>

Date::Date(const std::string &date_s /*= "1970-01-01"*/) {
  int count = 0;
  std::string curr_val;
  std::istringstream iss(date_s);
  while (std::getline(iss, curr_val, '-')) {
    switch (count) {
      case 0:
        
        break;
      case 1:
        
        break;
      case 2:
        
        break;
      default:
        throw InvalidDateException();
    }
    ++count;
  }
}

Date::Date(const Date &cpy) {}

Date::~Date() {}

Date &Date::operator=(const Date &other) {}

const char *Date::InvalidDateException::what() const throw() {
  return "Date is invalid!";
}

bool Date::validate() const {
  return true;
}
