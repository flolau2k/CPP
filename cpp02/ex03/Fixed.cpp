#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() { _store = 0; }

Fixed::Fixed(const int val) { _store = val << fract; }

Fixed::Fixed(const float val) { _store = roundf(val * (1 << fract)); }

Fixed::Fixed(const Fixed &F) { *this = F; }

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &F) {
  if (this != &F) {
    _store = F._store;
  }
  return *this;
}

bool Fixed::operator<(const Fixed &F) const {
  return _store < F._store;
}

bool Fixed::operator>(const Fixed &F) const { return (F < *this); }

bool Fixed::operator<=(const Fixed &F) const { return !(*this > F); }

bool Fixed::operator>=(const Fixed &F) const { return !(*this < F); }

bool Fixed::operator==(const Fixed &F) const {
  return _store == F.getRawBits();
}

bool Fixed::operator!=(const Fixed &F) const { return !(*this == F); }

Fixed Fixed::operator+(const Fixed &F) {
  Fixed ret;
  ret.setRawBits(getRawBits() + F.getRawBits());
  return ret;
}

Fixed Fixed::operator-(const Fixed &F) {
  Fixed ret;
  ret.setRawBits(getRawBits() - F.getRawBits());
  return ret;
}

Fixed Fixed::operator*(const Fixed &F) {
  Fixed ret;
  int64_t tmp = static_cast<int64_t>(getRawBits()) *
                static_cast<int64_t>(F.getRawBits());
  ret.setRawBits(static_cast<int32_t>(tmp >> fract));
  return ret;
}

Fixed Fixed::operator/(const Fixed &F) {
  Fixed ret;
  int64_t tmp = static_cast<int64_t>(getRawBits()) << fract;
  tmp /= F.getRawBits();
  ret.setRawBits(static_cast<int32_t>(tmp));
  return ret;
}

Fixed &Fixed::operator++() {
  this->_store++;
  return *this;
}

Fixed &Fixed::operator--() {
  this->_store--;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed ret = *this;
  this->_store++;
  return ret;
}

Fixed Fixed::operator--(int) {
  Fixed ret = *this;
  this->_store--;
  return ret;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  Fixed &ret = (a < b) ? a : b;
  return ret;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  const Fixed &ret = (a < b) ? a : b;
  return ret;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  Fixed &ret = (a > b) ? a : b;
  return ret;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  const Fixed &ret = (a > b) ? a : b;
  return ret;
}

int32_t Fixed::getRawBits(void) const { return _store; }

void Fixed::setRawBits(const int32_t raw) { _store = raw; }

float Fixed::toFloat(void) const { return float(_store) / (1 << fract); }

int Fixed::toInt(void) const { return getRawBits() >> fract; }

std::ostream &operator<<(std::ostream &out, const Fixed &F) {
  return out << F.toFloat();
}
