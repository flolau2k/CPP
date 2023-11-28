/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:20:19 by flauer            #+#    #+#             */
/*   Updated: 2023/11/28 11:19:13 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
  Fixed a;
	Fixed	b;

	a = Fixed(5.0f);
	b = Fixed(1.5f);

	std::cout << (a > b) << std::endl;
  // Fixed const	b(Fixed(5.05f) * Fixed(2));

  // std::cout << a << std::endl;
  // std::cout << ++a << std::endl;
  // std::cout << a << std::endl;
  // std::cout << a++ << std::endl;
  // std::cout << a << std::endl;

  // std::cout << b << std::endl;
  
	// std::cout << Fixed::max(a, b) << std::endl;
  
	return 0;
}