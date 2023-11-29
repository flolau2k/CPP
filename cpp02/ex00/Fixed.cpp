/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:20:21 by flauer            #+#    #+#             */
/*   Updated: 2023/11/29 10:54:46 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << DEFCONST << std::endl;
  _store = 0;
}

Fixed::Fixed(const Fixed &F) {
  std::cout << COPYCONST << std::endl;
  *this = F; // this uses the Copy assignment operator
  // this->_store = F.getRawBits(); // this does not.
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
