/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:52:59 by flauer            #+#    #+#             */
/*   Updated: 2023/08/17 15:30:42 by flauer           ###   ########.fr       */
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