/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:16:56 by flauer            #+#    #+#             */
/*   Updated: 2023/08/11 17:11:59 by flauer           ###   ########.fr       */
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
	this->firstname = get_input("First Name: ");
	this->lastname = get_input("Last Name: ");
	this->nickname = get_input("Nickname: ");
	this->phone_number = get_input("Phone Number: ");
	this->darkest_secret = get_input("Darkest Secret: ");
	return ;
}

void Contact::printContact()
{
	std::cout << "printing contact: " << this->firstname << std::endl;
	return ;
}
