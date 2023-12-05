#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

#define HAL "I'm sorry Dave, I'm afraid I can't do that"

class Point {
public:
  Point();
  Point(const float x, const float y);
  Point(const Point &P);
  ~Point();
  const Point &operator=(const Point &P) ;
  Fixed getX() const;
  Fixed getY() const;

private:
  Fixed const x;
  Fixed const y;
};

#endif // POINT_H