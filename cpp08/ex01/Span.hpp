#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstdlib>
#include <exception>

class Span {
public:
  Span(const size_t num);
  Span(const Span &cpy);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber();
  size_t shortestSpan();
  size_t longestSpan();

  class NothingStoredException : public std::exception {
  public:
    const char *what() const throw();
  };

private:

};

#endif // SPAN_HPP