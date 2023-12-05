#include "Point.hpp"

Point::Point() {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point &P) { *this = P; }

Point &Point::operator=(const Point &P) {
	std::cerr << "I'm sorry Dave, I'm afraid I can't do that" << std::endl;
	(void)P;
	return *this;
}

Point::~Point() {}
