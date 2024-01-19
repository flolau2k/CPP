#ifndef MY_CSV_HPP
#define MY_CSV_HPP

#include <string>
#include <map>

class My_CSV {
public:
  My_CSV(const std::string &filename);
  ~My_CSV();
  
  const std::map<std::string, double> &get_map() const;

private:
  My_CSV();
  My_CSV &operator=(const My_CSV &other);

  double stod(std::string &s);

  class ExtractionFailException : public std::exception {
  public:
    const char *what() const throw();
  };

  std::map<std::string, double> _data;
};

#endif // MY_CSV_HPP