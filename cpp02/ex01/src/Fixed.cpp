/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:36:36 by flauer            #+#    #+#             */
/*   Updated: 2023/10/26 15:47:03 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() {
  std::cout << DEFCONST << std::endl;
  _store = 0;
}

Fixed::Fixed(const int val) {
  std::cout << INTCONST << std::endl;
  _store = val << fract;
}

Fixed::Fixed(const float val) {
  std::cout << FLOATCONST << std::endl;
  _store = roundf(val * (1 << fract));
}

Fixed::Fixed(const Fixed &F) {
  std::cout << COPYCONST << std::endl;
  *this = F;
}

Fixed::~Fixed() { std::cout << DESTRUCT << std::endl; }

Fixed &Fixed::operator=(const Fixed &F) {
  std::cout << COPYASSIGN << std::endl;
  if (this != &F) {
    this->_store = F.getRawBits();
  }
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << GETRAWC << std::endl;
  return _store;
}

void Fixed::setRawBits(const int raw) {
  std::cout << SETRAWC << std::endl;
  _store = raw;
}

/// @brief convert Fixed to float. Create a float from the _store integer and
/// devide it by the number fractional bits.
/// @param void
/// @return floating point representation of Fixed
float Fixed::toFloat(void) const {
	return float(_store) / (1 << fract); 
}

int Fixed::toInt(void) const {
	return roundf(this->toFloat()); 
}

std::ostream &operator<<(std::ostream &out, const Fixed &F) {
  return out << F.toFloat();
}
