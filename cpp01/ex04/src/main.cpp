/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:19:31 by flauer            #+#    #+#             */
/*   Updated: 2023/08/15 14:23:37 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

static bool	check_input(int argc, char **argv, char **env)
{
	
}

int	main(int argc, char **argv, char **env)
{
	std::ifstream	input_file;
	std::ofstream	output_file;

	if (!check_input(argc, argv, env))
		return (EXIT_FAILURE);
	
	return (0);
}
