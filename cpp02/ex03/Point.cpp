#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point &P) { *this = P; }

Point &Point::operator=(const Point &P) : x(P.x), y(P.y) {}