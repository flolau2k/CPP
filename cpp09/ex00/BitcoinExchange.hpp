#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include "Date.hpp"

class BitcoinExchange {
public:
  BitcoinExchange();
  BitcoinExchange(const std::string &filename);
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &cpy);
  ~BitcoinExchange();
  
  const std::map<Date, double> &get_map() const;
  void read_csv(const std::string &filename);

  class NoDataException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  class CSVParsingException : public std::exception {
  public:
    const char *what() const throw();
  };

  double stod(std::string &s);

  std::map<Date, double> _data;
};

#endif // BITCOINEXCHANGE_HPP