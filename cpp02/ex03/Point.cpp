#include "Point.hpp"

Point::Point() {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point &P) : x(P.x), y(P.y) {
  std::cout << COPYCONST << std::endl;
}

// returning a reference to the same object since the members x and y are const
// and the same values.
const Point &Point::operator=(const Point &P) {
  std::cerr << HAL << std::endl;
  (void)P;
  return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
  return x;
}

Fixed Point::getY() const {
  return y;
}
