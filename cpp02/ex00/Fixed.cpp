#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << DEFCONST << std::endl;
  _store = 0;
}

Fixed::Fixed(const Fixed &F) {
  std::cout << COPYCONST << std::endl;
  *this = F; // this uses the Copy assignment operator
  // _store = F.getRawBits(); // this does not.
}

Fixed::~Fixed() { std::cout << DESTRUCT << std::endl; }

Fixed &Fixed::operator=(const Fixed &F) {
  std::cout << COPYASSIGN << std::endl;
  if (this != &F) {
    _store = F.getRawBits();
  }
  return *this;
}

int32_t Fixed::getRawBits(void) const {
  std::cout << GETRAWC << std::endl;
  return _store;
}

void Fixed::setRawBits(const int32_t raw) {
  std::cout << SETRAWC << std::endl;
  _store = raw;
}
