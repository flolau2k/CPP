/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:20:16 by flauer            #+#    #+#             */
/*   Updated: 2023/11/29 11:17:03 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

  int getRawBits(void) const;
  void setRawBits(const int raw);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int _store;
  static const int fract = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &F);

#endif