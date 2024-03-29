#include "Span.hpp"
#include <limits>

const char *Span::NotEnoughValuesStoredException::what() const throw() {
  return "Not Enough Values stored to calculate the Span!";
}

const char *Span::NoSpaceLeftException::what() const throw() {
  return "There is no Space left in this Span!";
}

Span::Span(const size_t num /* = 0 */) {
  _vec = std::vector<int>(0);
  _size = num;
}

Span::Span(const Span &cpy) {
  *this = cpy;
}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _vec = other._vec;
    _size = other._size;
  }
  return *this;
}

void Span::addNumber(int number) {
  if (_vec.size() < _size)
    _vec.push_back(number);
  else
    throw NoSpaceLeftException();
}

std::vector<int> Span::get_vec() const {
  return _vec;
}

unsigned int Span::longestSpan() {
  if (_vec.size() < 2)
    throw NotEnoughValuesStoredException();
  int highest = std::numeric_limits<int>::min();
  int lowest = std::numeric_limits<int>::max();
  for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it) {
    if (*it > highest) highest = *it;
    if (*it < lowest) lowest = *it;
  }
  return static_cast<unsigned int>(highest - lowest);
}

unsigned int Span::shortestSpan() {
  if (_vec.size() < 2)
    throw NotEnoughValuesStoredException();
  int shortestSpan = std::numeric_limits<int>::max();
  for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it) {
    for (std::vector<int>::iterator it2 = it + 1; it2 != _vec.end(); ++it2) {
      if (abs(*it - *it2) < shortestSpan) shortestSpan = abs(*it - *it2);
    }
  }
  return static_cast<unsigned int>(shortestSpan);
}
