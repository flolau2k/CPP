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

  void addNumber(int number);
  
  template <typename Iter>
  void addRange(Iter first, Iter last) {
    Iter it = first;
    while (it != last) {
      this->addNumber(*it);
      it++;
    }
  }
  
  size_t shortestSpan();
  size_t longestSpan();

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