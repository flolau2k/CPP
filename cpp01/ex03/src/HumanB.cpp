/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:42:02 by flauer            #+#    #+#             */
/*   Updated: 2023/11/22 09:48:45 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) 
{
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void HumanB::attack()
{
	if (!_weapon)
	{
		std::cout << _name << " attacks with their bare fists" << std::endl;
		return ;
	}
	std::cout << _name << " attacks with their " 
		<< _weapon->getType() << std::endl;
	return ;
}
