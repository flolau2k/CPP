/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:42:22 by flauer            #+#    #+#             */
/*   Updated: 2023/08/14 18:02:30 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon(){}

std::string	Weapon::getType(void) const
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}
