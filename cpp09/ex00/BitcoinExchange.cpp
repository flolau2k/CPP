#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
// #include <time.h>

const char *BitcoinExchange::CSVParsingException::what() const throw() {
  return "csv parsing failed!";
}

const char *BitcoinExchange::NoDataException::what() const throw() {
  return "no data stored!";
}

double BitcoinExchange::stod(std::string &s) {
  std::istringstream iss(s);
  double val;
  iss >> val;
  if (iss.fail()) throw CSVParsingException();
  return val;
}

bool check_date_arg(std::string &arg, int min, int max) {
  std::istringstream iss(arg);
  int val;
  iss >> val;
  if (iss.fail()) return false;
  if (val >= min && val <= max) return true;
  return false;
}

bool check_leap_year(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    return true;
  else
    return false;
}

void BitcoinExchange::check_date(const std::string &date) const {
  int count = 0;
  std::string curr_val;
  std::istringstream iss(date);
  while (std::getline(iss, curr_val, '-')) {
    switch (count) {
      case 0:
        if (curr_val.length() != 4) throw CSVParsingException();
        if (!check_date_arg(curr_val, 0, 9999)) throw CSVParsingException();
        break;
      case 1:
        if (curr_val.length() != 2) throw CSVParsingException();
        if (!check_date_arg(curr_val, 1, 12)) throw CSVParsingException();
        break;
      case 2:
        if (curr_val.length() != 2) throw CSVParsingException();
        if (!check_date_arg(curr_val, 1, 31)) throw CSVParsingException();
        break;
    }
    ++count;
  }
}

// void BitcoinExchange::check_date(const std::string &date) const {
//   (void) date;
//   struct tm start = {};
//   start.tm_mday = 31;
//   start.tm_mon = 1,
//   start.tm_year = 2009 - 1900;
//   time_t time = mktime(&start);
//   std::cout << asctime(&start);
// }

void BitcoinExchange::read_csv(const std::string &filename) {
  std::ifstream data_f(filename.c_str());
  std::pair<std::string, double> curr_set;
  std::string curr_val_s;
  double curr_val;
  std::string curr_line;
  std::string curr_date;

  if (data_f.is_open()) {
    while (std::getline(data_f, curr_line)) {
      if (curr_line == "date,exchange_rate") continue;
      curr_date = curr_line.substr(0, curr_line.find(","));
      try {
        check_date(curr_date);
      } catch (CSVParsingException &e) {
        std::cerr << "invalid date found: " << curr_date << std::endl;
        continue;
      }
      curr_val_s = curr_line.substr(curr_line.find(",") + 1);
      try {
        curr_val = stod(curr_val_s);
      } catch (CSVParsingException &e) {
        std::cerr << "invalid value found: " << curr_val_s << std::endl;
      }
      curr_set = std::pair<std::string, double>(curr_date, curr_val);
      _data.insert(curr_set);
    }
  }
  data_f.close();
}

BitcoinExchange::BitcoinExchange(const std::string &filename) {
  read_csv(filename);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
  *this = cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    _data = other._data;
  }
  return *this;
}

const std::map<std::string, double> &BitcoinExchange::get_map() const {
  return _data;
}
