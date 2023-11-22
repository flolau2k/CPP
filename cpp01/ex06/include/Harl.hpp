/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:53:02 by flauer            #+#    #+#             */
/*   Updated: 2023/11/22 11:43:25 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cstdlib>

# define DEBUG_S "DEBUG: Gathering dirty clothes"
# define INFO_S "INFO: Going to do the Laundry"
# define WARNING_S "WARNING: Found a penny in a Pocket!"
# define ERROR_S "ERROR: a brick found its way into the machine and it exploded"
# define INSIGNIFICANT_S "[ Probably complaining about insignificant problems ]"


class Harl {
	private:
		const static std::string levels[4];
		void (Harl::*functions[4])(void) const;
		
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error(void) const;

	public:
		Harl();
		~Harl();
		void complain(std::string level);
		enum Level {DEBUG, INFO, WARNING, ERROR, INSIGNIFICANT}; 
};

#endif
