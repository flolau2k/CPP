#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cstdlib>

#define COPYASSIGN "Copy assignment operator called"
#define DESTRUCT "Destructor called"
#define DEFCONST "Default constructor called"
#define GETRAWC "getRawBits member function called"
#define SETRAWC "setRawBits member function called"
#define COPYCONST "Copy constructor called"
#define INTCONST "Int constructor called"
#define FLOATCONST "Float constructor called"

class Fixed {
public:
  Fixed();
  Fixed(const int val);
  Fixed(const float val);
  Fixed(const Fixed &F);
  Fixed &operator=(const Fixed &F);
  ~Fixed();

  int32_t getRawBits(void) const;
  void setRawBits(const int32_t raw);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int32_t _store;
  static const int fract = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &F);

#endif