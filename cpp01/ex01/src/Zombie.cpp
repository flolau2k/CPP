/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:16:59 by flauer            #+#    #+#             */
/*   Updated: 2023/11/21 16:58:41 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name) { _name = name; }

Zombie::Zombie() {}

Zombie::~Zombie() { std::cout << "Destructing Zombie: " << _name << std::endl; }

void Zombie::announce() const {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
  return;
}

void Zombie::set_name(std::string name) { _name = name; }
