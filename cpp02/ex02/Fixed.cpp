/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:36:36 by flauer            #+#    #+#             */
/*   Updated: 2023/11/29 15:19:51 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

bool Fixed::operator<(const Fixed &F) const {
	return this->_store < F.getRawBits();
}

bool Fixed::operator>(const Fixed &F) const {
	return (F < *this);
}

bool Fixed::operator<=(const Fixed &F) const {
	return !(*this > F);
}

bool Fixed::operator>=(const Fixed &F) const {
	return !(*this < F);
}

bool Fixed::operator==(const Fixed &F) const {
	return this->_store == F.getRawBits();
}

bool Fixed::operator!=(const Fixed &F) const {
	return !(*this == F);
}

Fixed Fixed::operator+(const Fixed &F) {
	Fixed ret;
	ret.setRawBits(this->getRawBits() + F.getRawBits());
	return ret;
}

Fixed Fixed::operator-(const Fixed &F) {
	Fixed ret;
	ret.setRawBits(this->getRawBits() - F.getRawBits());
	return ret;
}

Fixed Fixed::operator*(const Fixed &F) {
	Fixed ret;
	int64_t tmp = static_cast<int64_t>(this->getRawBits())
		* static_cast<int64_t>(F.getRawBits());
	ret.setRawBits(static_cast<int>(tmp >> this->fract));
	return ret;
}

Fixed Fixed::operator/(const Fixed &F) {
	Fixed ret;
	
}

int Fixed::getRawBits(void) const {
  // std::cout << GETRAWC << std::endl;
  return _store;
}

void Fixed::setRawBits(const int raw) {
  // std::cout << SETRAWC << std::endl;
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
