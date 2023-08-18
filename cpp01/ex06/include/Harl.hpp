/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:53:02 by flauer            #+#    #+#             */
/*   Updated: 2023/08/18 11:13:00 by flauer           ###   ########.fr       */
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


class Harl {
	private:
		const static std::string levels[4];
		void (Harl::*functions[4])(void);
		
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl();
		~Harl();
		void complain(std::string level);
		enum Level {DEBUG, INFO, WARNING, ERROR}; 
};

#endif
