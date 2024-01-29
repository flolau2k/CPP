#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

const char *BitcoinExchange::CSVParsingException::what() const throw() {
  return "csv parsing failed!";
}

const char *BitcoinExchange::NoDataException::what() const throw() {
  return "no data stored!";
}

const char *BitcoinExchange::InvalidDataException::what() const throw() {
  return "Input Data is invalid!";
}

const char *BitcoinExchange::BadFileException::what() const throw() {
  return "Bad File!";
}

const char *BitcoinExchange::FileOpenException::what() const throw() {
  return "could not open file!";
}

double BitcoinExchange::stod(std::string &s) const {
  std::istringstream iss(s);
  double val;
  iss >> val;
  if (iss.fail())
    throw CSVParsingException();
  return val;
}

BitcoinExchange::DateValueMap
BitcoinExchange::read_file(std::ifstream &ifile, const std::string &delim) const {
  std::string curr_line;
  std::string curr_date_s;
  std::string curr_val_s;
  Date curr_date;
  double curr_val;
  std::pair<Date, double> curr_set;
  BitcoinExchange::DateValueMap ret;

  if (!ifile.good())
    throw BadFileException();
  while (std::getline(ifile, curr_line)) {
    if (curr_line.find("date") != std::string::npos)
      continue;
    curr_date_s = curr_line.substr(0, curr_line.find(delim));
    try {
      curr_date = Date(curr_date_s);
    } catch (Date::InvalidDateException &e) {
      std::cerr << "Error: invalid date found: " << curr_date_s << std::endl;
      continue;
    }
    curr_val_s = curr_line.substr(curr_line.find(delim) + 1);
    try {
      curr_val = stod(curr_val_s);
    } catch (CSVParsingException &e) {
      std::cerr << "Error: invalid value found: " << curr_val_s << std::endl;
      continue;
    }
    curr_set = std::pair<Date, double>(curr_date, curr_val);
    ret.insert(curr_set);
  }
  ifile.close();
  return ret;
}

void BitcoinExchange::read_data(const std::string &filename) {
  std::ifstream ifs(filename.c_str());
  if (!ifs.is_open()) throw FileOpenException();
  _data = read_file(ifs, ",");
}

void BitcoinExchange::read_input(const std::string &filename) {
  std::ifstream ifs(filename.c_str());
  if (!ifs.is_open()) throw FileOpenException();
  _input = read_file(ifs, "|");
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) { *this = cpy; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    _data = other._data;
  }
  return *this;
}
