#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

const char *BitcoinExchange::ExtractionFailException::what() const throw() {
  return "extraction failed!";
}

double BitcoinExchange::stod(std::string &s) {
  std::istringstream iss(s);
  double val;
  iss >> val;
  if (iss.fail()) throw ExtractionFailException();
  return val;
}

BitcoinExchange::BitcoinExchange(const std::string &filename) {
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
      curr_val_s = curr_line.substr(curr_line.find(",") + 1);
      curr_val = stod(curr_val_s);
      curr_set = std::pair<std::string, double>(curr_date, curr_val);
      _data.insert(curr_set);
    }
  }
  data_f.close();
}

BitcoinExchange::~BitcoinExchange() {}

const std::map<std::string, double> &BitcoinExchange::get_map() const {
  return _data;
}
