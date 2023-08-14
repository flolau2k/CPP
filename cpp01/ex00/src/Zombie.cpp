/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:16:59 by flauer            #+#    #+#             */
/*   Updated: 2023/08/14 16:28:15 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string _name)
{
	Zombie::name = _name;
}

Zombie::Zombie() {}

Zombie::~Zombie() 
{
	std::cout << "Destructing Zombie: " << name << std::endl;
}

void Zombie::announce() const
{
	std::cout << name
		<< ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
