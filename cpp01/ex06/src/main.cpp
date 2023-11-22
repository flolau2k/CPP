/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:52:46 by flauer            #+#    #+#             */
/*   Updated: 2023/11/22 11:44:49 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

static void	print_usage(void)
{
	std::cerr << "This program takes only one argument. " << std::endl
		<< "This Argument specifies the minimum loglevel to display." << std::endl;
}

static bool	check_args(int argc, char **argv, Harl::Level &l)
{
	if (argc != 2)
		return (false);
	const std::string arg = argv[1];
	if (!arg.compare("DEBUG"))
		l = Harl::DEBUG;
	else if (!arg.compare("INFO"))
		l = Harl::INFO;
	else if (!arg.compare("WARNING"))
		l = Harl::WARNING;
	else if (!arg.compare("ERROR"))
		l = Harl::ERROR;
	else
		l = Harl::INSIGNIFICANT;
	return (true);
}

int main(int argc, char **argv)
{
	Harl::Level		l;
	Harl			h;

	if (!check_args(argc, argv, l))
		return (print_usage(), EXIT_FAILURE);

	switch(l)
	{
		case Harl::DEBUG:
			h.complain("debug");
			/* fall through */
		case Harl::INFO:
			h.complain("info");
			/* fall through */
		case Harl::WARNING:
			h.complain("warning");
			/* fall through */
		case Harl::ERROR:
			h.complain("error");
			break;
		case Harl::INSIGNIFICANT:
			std::cout << INSIGNIFICANT_S << std::endl;
	}
	return (EXIT_SUCCESS);
}
