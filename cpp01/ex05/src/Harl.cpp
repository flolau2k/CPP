/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:52:59 by flauer            #+#    #+#             */
/*   Updated: 2023/08/17 12:42:09 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl() {
	levels["debug"] = &Harl::debug;
	levels["info"] = &(Harl::info);
	levels["warning"] = &Harl::warning;
	levels["error"] = &Harl::error;
}
Harl::~Harl() {}

void Harl::complain(std::string level)
{
	levels_t::iterator iter = levels.find(level);
	if (iter == levels.end())
		std::cout << "NOT FOUND!" << std::endl;
	else
		std::cout << "foudn" << std::endl;
}

void Harl::debug(void)
{
	std::cout << DEBUG << std::endl;
}

void Harl::info(void)
{
	std::cout << INFO << std::endl;
}

void Harl::warning(void)
{
	std::cout << WARNING << std::endl;
}

void Harl::error(void)
{
	std::cout << ERROR << std::endl;
}