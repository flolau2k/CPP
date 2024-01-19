#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
  BitcoinExchange(const std::string &filename);
  ~BitcoinExchange();
  
  const std::map<std::string, double> &get_map() const;

private:
  BitcoinExchange();
  BitcoinExchange &operator=(const BitcoinExchange &other);

  double stod(std::string &s);

  class ExtractionFailException : public std::exception {
  public:
    const char *what() const throw();
  };

  std::map<std::string, double> _data;
};

#endif // BITCOINEXCHANGE_HPP