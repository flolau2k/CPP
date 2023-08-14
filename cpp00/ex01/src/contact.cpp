/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:16:56 by flauer            #+#    #+#             */
/*   Updated: 2023/08/14 11:07:24 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string Contact::get_input(const std::string prompt)
{
	std::string buf;
	std::cout << prompt;
	std::getline(std::cin, buf);
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
	std::cout << "First Name: " << firstname << std::endl
		<< "Last Name: " << lastname << std::endl
		<< "Nick Name: " << nickname << std::endl
		<< "Phone Number: " << phone_number << std::endl
		<< "Darkest Secret: " << darkest_secret << std::endl;
	return ;
}

std::string Contact::get_firstname()
{
	return firstname;
}

std::string Contact::get_lastname()
{
	return lastname;
}

std::string Contact::get_nickname()
{
	return nickname;
}

std::string Contact::get_phone()
{
	return phone_number;
}

std::string Contact::get_secret()
{
	return darkest_secret;
}
