#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstdlib>
#include <exception>
#include <vector>

class Span {
public:
  Span(const size_t num = 0);
  Span(const Span &cpy);
  Span &operator=(const Span &other);
  ~Span();

  template<typename iter>
  void insert(iter begin, iter end) {
    _vec.insert(_vec.end(), begin, end);
  }
  void addNumber(int number);
  std::vector<int> get_vec() const;

  unsigned int shortestSpan();
  unsigned int longestSpan();

  class NotEnoughValuesStoredException : public std::exception {
  public:
    const char *what() const throw();
  };

  class NoSpaceLeftException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  std::vector<int> _vec;
  size_t _size;
};

#endif // SPAN_HPP