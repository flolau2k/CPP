/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:20:16 by flauer            #+#    #+#             */
/*   Updated: 2023/08/18 16:19:26 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define COPYASSIGN "Copy assignment operator called"
# define DESTRUCT "Destructor called"
# define DEFCONST "Default constructor called"
# define GETRAWC "getRawBits member function called"
# define SETRAWC "setRawBits member function called"
# define COPYCONST "Copy constructor called"

class Fixed 
{
	public:
		Fixed();
		Fixed(const Fixed &F);
		Fixed &operator=(const Fixed &F);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(const int raw);

	private:
		int					_store;
		static const int	fract = 8;
};

#endif