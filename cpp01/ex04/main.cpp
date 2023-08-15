/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:19:31 by flauer            #+#    #+#             */
/*   Updated: 2023/08/15 16:53:21 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

static bool	check_input(int &argc, char **&argv, char **&env)
{
	(void)argc;
	(void)argv;
	(void)env;
	return (true);
}

static void	replace_in_line(std::string &line, std::string &s1, std::string &s2)
{
	int		len = s1.length();
	size_t	i = 0;

	i = line.find(s1, i);
	while (i != std::string::npos)
	{
		line.erase(i, len);
		line.insert(i, s2);
		i = line.find(s1, i);
	}
	return ;
}

int	main(int argc, char **argv, char **env)
{
	std::ifstream	input_file;
	std::ofstream	output_file;
	std::string		s1, s2, line, ofilename;

	if (!check_input(argc, argv, env))
		return (EXIT_FAILURE);
	
	input_file.open(argv[1], std::ifstream::in);
	if (!input_file)
		return (std::cout << "cannot open infile: " << argv[1] << std::endl, 1);
	ofilename = std::string(argv[1]) + ".replace";
	output_file.open(ofilename.c_str(), std::ofstream::out | std::ofstream::trunc);
	s1 = argv[2];
	s2 = argv[3];
	if (!output_file)
		return (std::cout << "cannot open outfile: " << ofilename << std::endl, 1);
	while (std::getline(input_file, line))
	{
		replace_in_line(line, s1, s2);
		output_file << line << std::endl;
	}

	return (0);
}
