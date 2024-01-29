#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Date.hpp"
#include <map>
#include <string>

class BitcoinExchange {
public:
  typedef std::map<Date, double> DateValueMap;
  typedef std::pair<Date, double> DataPoint;

  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &cpy);
  ~BitcoinExchange();

  void read_data(const std::string &filename);
  void read_input(const std::string &filename);

  class NoDataException : public std::exception {
  public:
    const char *what() const throw();
  };

  class InvalidDataException : public std::exception {
  public:
    const char *what() const throw();
  };

  class BadFileException : public std::exception {
  public:
    const char *what() const throw();
  };

  class OpenFileException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  class CSVParsingException : public std::exception {
  public:
    const char *what() const throw();
  };

  double stod(std::string &s) const;
  DateValueMap read_file(std::ifstream &ifile, const std::string &delim) const;
  DataPoint getPairFromLine(const std::string &line,
                            const std::string &delim) const;

  DateValueMap _data;
};

#endif // BITCOINEXCHANGE_HPP