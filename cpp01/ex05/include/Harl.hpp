/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:53:02 by flauer            #+#    #+#             */
/*   Updated: 2023/08/17 12:41:01 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <map>

# define DEBUG "DEBUG: Gathering dirty clothes"
# define INFO "INFO: Going to do the Laundry"
# define WARNING "WARNING: Found a penny in a Pocket!"
# define ERROR "ERROR: Found a brick in a Pocket!"


class Harl {
	typedef void (Harl::*Func)(void);
	typedef std::map<std::string, Func> levels_t;
	private: 
		const levels_t levels;

		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};


#endif