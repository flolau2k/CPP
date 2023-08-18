/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:52:46 by flauer            #+#    #+#             */
/*   Updated: 2023/08/18 11:13:18 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

static void	print_usage(void)
{
	std::cerr << "This program takes only one argument. " << std::endl
		<< "This Argument may be one of the following:" << std::endl
		<< "\"DEBUG\", \"INFO\", \"WARNING\", \"ERROR\"" << std::endl;
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
		return (false);
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
		case Harl::INFO:
			h.complain("info");
		case Harl::WARNING:
			h.complain("warning");
		case Harl::ERROR:
			h.complain("error");
	}
	return (EXIT_SUCCESS);
}
