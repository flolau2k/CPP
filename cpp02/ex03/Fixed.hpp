#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define COPYASSIGN "Copy assignment operator called"
#define DESTRUCT "Destructor called"
#define DEFCONST "Default constructor called"
#define COPYCONST "Copy constructor called"
#define INTCONST "Int constructor called"
#define FLOATCONST "Float constructor called"

class Fixed {
public:
  Fixed();
  Fixed(const int val);
  Fixed(const float val);
  Fixed(const Fixed &F);
  ~Fixed();

  Fixed &operator=(const Fixed &F);
  bool operator>(const Fixed &F) const;
  bool operator<(const Fixed &F) const;
  bool operator>=(const Fixed &F) const;
  bool operator<=(const Fixed &F) const;
  bool operator==(const Fixed &F) const;
  bool operator!=(const Fixed &F) const;
  Fixed operator+(const Fixed &F);
  Fixed operator-(const Fixed &F);
  Fixed operator*(const Fixed &F);
  Fixed operator/(const Fixed &F);
  Fixed &operator++();
  Fixed &operator--();
  Fixed operator++(int);
  Fixed operator--(int);

  int32_t getRawBits(void) const;
  void setRawBits(const int32_t raw);
  float toFloat(void) const;
  int toInt(void) const;

  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

private:
  int32_t _store;
  static const int fract = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &F);

#endif
