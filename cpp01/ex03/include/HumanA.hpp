/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:45:40 by flauer            #+#    #+#             */
/*   Updated: 2023/08/14 18:35:42 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA {
	private:
		std::string	_name;
		Weapon&		_weapon;
	
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack();
};

#endif