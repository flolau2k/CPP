/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:52:59 by flauer            #+#    #+#             */
/*   Updated: 2023/08/18 11:01:07 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

const std::string Harl::levels[] = {"debug", "info", "warning", "error"};

Harl::Harl() {
	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;
}
Harl::~Harl() {}

void Harl::complain(std::string level)
{
	for (size_t i = 0; i < levels->length(); i++)
	{
		if (level.compare(levels[i]) == 0)
			return (this->*functions[i])();
	}
}

void Harl::debug(void)
{
	std::cout << DEBUG_S << std::endl;
}

void Harl::info(void)
{
	std::cout << INFO_S << std::endl;
}

void Harl::warning(void)
{
	std::cout << WARNING_S << std::endl;
}

void Harl::error(void)
{
	std::cout << ERROR_S << std::endl;
}
