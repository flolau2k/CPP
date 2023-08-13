/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:16:56 by flauer            #+#    #+#             */
/*   Updated: 2023/08/13 14:28:22 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

static std::string get_input(std::string prompt = "input: ")
{
	std::string buf;
	std::cout << prompt;
	std::cin >> buf;
	return (buf);
}

Contact::Contact() {
  // std::cout << "Contact constructor called!" << std::endl;
}

Contact::~Contact() {}

void Contact::fillContact()
{
	firstname = get_input("First Name: ");
	lastname = get_input("Last Name: ");
	nickname = get_input("Nickname: ");
	phone_number = get_input("Phone Number: ");
	darkest_secret = get_input("Darkest Secret: ");
	return ;
}

void Contact::printContact()
{
	std::cout << "printing contact: " << firstname << std::endl;
	return ;
}
