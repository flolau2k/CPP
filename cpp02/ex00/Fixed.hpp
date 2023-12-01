#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define COPYASSIGN "Copy assignment operator called"
#define DESTRUCT "Destructor called"
#define DEFCONST "Default constructor called"
#define GETRAWC "getRawBits member function called"
#define SETRAWC "setRawBits member function called"
#define COPYCONST "Copy constructor called"

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed &F);
  Fixed &operator=(const Fixed &F);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(const int raw);

 private:
  int _store;
  static const int fract = 8;
};

#endif