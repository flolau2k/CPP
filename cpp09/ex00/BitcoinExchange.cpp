#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>

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

const char *BitcoinExchange::OpenFileException::what() const throw() {
  return "could not open file!";
}

double BitcoinExchange::stod(std::string &s) const {
  std::istringstream iss(s);
  double val;
  iss >> val;
  if (iss.fail())
    throw BitcoinExchange::CSVParsingException();
  return val;
}

BitcoinExchange::DataPoint
BitcoinExchange::getPairFromLine(const std::string &line,
                                 const std::string &delim) const {
  std::string date_s;
  std::string val_s;
  Date date;
  double val;
  BitcoinExchange::DataPoint ret;

  date_s = line.substr(0, line.find(delim));
  try {
    date = Date(date_s);
  } catch (Date::InvalidDateException &e) {
    std::cerr << "Error: invalid date found: " << date_s << std::endl;
    throw InvalidDataException();
  }
  val_s = line.substr(line.find(delim) + 1);
  try {
    val = stod(val_s);
  } catch (BitcoinExchange::CSVParsingException &e) {
    std::cerr << "Error: invalid value found: " << val_s << std::endl;
    throw InvalidDataException();
  }
  if (val < 0) {
    std::cerr << "Error: not a positive number: " << val << std::endl;
    throw InvalidDataException();
  }
  ret = BitcoinExchange::DataPoint(date, val);
  return ret;
}

BitcoinExchange::DateValueMap
BitcoinExchange::read_file(std::ifstream &ifile,
                           const std::string &delim) const {
  std::string curr_line;
  std::pair<Date, double> curr_set;
  BitcoinExchange::DateValueMap ret;

  if (!ifile.good())
    throw BadFileException();
  while (std::getline(ifile, curr_line)) {
    if (curr_line.find("date") != std::string::npos)
      continue;
    curr_set = getPairFromLine(curr_line, delim);
    if (ret.find(curr_set.first) != ret.end()) {
      std::cerr << "Error: multiple entries for date " << curr_set.first
                << ". Skipping..." << std::endl;
      continue;
    }
    ret.insert(curr_set);
  }
  return ret;
}

void BitcoinExchange::read_data(const std::string &filename) {
  std::ifstream ifs(filename.c_str());
  if (!ifs.is_open())
    throw OpenFileException();
  _data = read_file(ifs, ",");
  ifs.close();
}

void BitcoinExchange::read_input(const std::string &filename) {
  std::ifstream ifs(filename.c_str());
  std::string curr_line;
  BitcoinExchange::DataPoint curr_entry;
  BitcoinExchange::DateValueMap::iterator data_it;

  if (_data.size() <= 0)
    throw NoDataException();
  if (!ifs.is_open())
    throw OpenFileException();
  if (!ifs.good())
    throw BadFileException();

  while (std::getline(ifs, curr_line)) {
    if (curr_line.find("date") != std::string::npos)
      continue;
    try {
      curr_entry = getPairFromLine(curr_line, "|");
    } catch (std::exception &e) {
      continue;
    }
    data_it = _data.lower_bound(curr_entry.first);
    if (data_it == _data.end()) {
      data_it--;
      std::cout << "Warning: Last Data Point is at " << data_it->first
                << std::endl;
    } else if (data_it == _data.begin()) {
      std::cerr << "Error: No Data for " << curr_entry.first
                << ". First Data point is at " << data_it->first << std::endl;
      continue;
    } else  if (curr_entry.first < data_it->first) {
      data_it--;
    }
    if (curr_entry.second > _max_value) {
      std::cerr << "Error: too large a number." << std::endl;
      continue;
    }
    double value = data_it->second * curr_entry.second;
    std::cout << curr_entry.first << " => " << curr_entry.second << " = "
              << value << std::endl;
  }
  ifs.close();
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
