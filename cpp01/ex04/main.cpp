/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:19:31 by flauer            #+#    #+#             */
/*   Updated: 2023/11/22 10:29:44 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>

static bool check_input(int &argc, char **&argv) {
  if (argc != 4)
    return (std::cerr << "Wrong number of Arguments!" << std::endl, false);
  if (std::string(argv[2]).length() <= 0 || std::string(argv[3]).length() <= 0)
    return (std::cerr << "s1 and s2 cannot be empty!" << std::endl, false);
  return (true);
}

static void replace_in_line(std::string &line, std::string &s1,
                            std::string &s2) {
  const int len = s1.length();
  size_t i = 0;

  i = line.find(s1, i);
  while (i != std::string::npos) {
    line.erase(i, len);
    line.insert(i, s2);
    i = line.find(s1, i);
  }
  return;
}

int main(int argc, char **argv) {
  std::ifstream input_file;
  std::ofstream output_file;
  std::string s1, s2, line, ofilename;

  if (!check_input(argc, argv))
    return (EXIT_FAILURE);

  input_file.open(argv[1]);
  if (!input_file)
    return (std::cerr << std::strerror(errno) << ": \"" << argv[1] << "\""
                      << std::endl,
            EXIT_FAILURE);
  ofilename = std::string(argv[1]) + ".replace";
  output_file.open(ofilename.c_str(), std::ofstream::trunc);
  if (!output_file)
    return (std::cerr << std::strerror(errno) << ": \"" << ofilename << "\""
                      << std::endl,
            EXIT_FAILURE);
  s1 = std::string(argv[2]);
  s2 = std::string(argv[3]);
  while (std::getline(input_file, line)) {
    replace_in_line(line, s1, s2);
    output_file << line << std::endl;
  }

  return (0);
}
