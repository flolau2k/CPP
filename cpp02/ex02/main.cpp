#include "Fixed.hpp"

int main(void) {
  // Fixed	b;

  // b = Fixed(1.5f);

  // std::cout << (b < a) << std::endl;
  // std::cout << (b > a) << std::endl;

  // Fixed c = a + b;

  // std::cout << c << std::endl;
  // std::cout << a << std::endl;

  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << Fixed::max(a, b) << std::endl;

  return 0;
}