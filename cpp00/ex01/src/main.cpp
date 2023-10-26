/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:24:06 by flauer            #+#    #+#             */
/*   Updated: 2023/10/26 10:06:15 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void print_help()
{
	std::cout << "Available Commands are: " << std::endl
		<< "ADD: Adds a new contact to the list. " << std::endl
		<< "SEARCH: List the contacts in the List." << std::endl
		<< "EXIT: Quit the program, all data will be lost." << std::endl
		<< "HELP: Display this help message." << std::endl;
}

int main(void) {
  PhoneBook pb;
  std::string buf;

  std::cout << "Welcome to this wonderful PhoneBook!" << std::endl;
  while (true) {
	if (std::cin.eof()) break;
    std::cout << "> ";
    std::getline(std::cin, buf);
    if (buf == "ADD")
		pb.AddContact();
	else if (buf == "SEARCH")
		pb.SearchContact();
	else if (buf == "EXIT")
		break;
	else
		print_help();
  }
  return (0);
}