#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
public:
  Point();
  Point(const float x, const float y);
  Point(const Point &P);
  ~Point();

  Point &operator=(const Point &P);

private:
  Fixed const x;
  Fixed const y;
};

#endif // POINT_H