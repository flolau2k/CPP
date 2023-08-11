/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:16:55 by flauer            #+#    #+#             */
/*   Updated: 2023/08/11 17:14:44 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() 
{
	this->oldest = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::AddContact() {
	std::cout << "Add new Contact:" << std::endl; 
	this->contacts[this->oldest].fillContact();
	this->oldest++;
	if (this->oldest > MAX_CONTACTS)
		this->oldest = 0;
	return ;
}

void PhoneBook::SearchContact()
{
	std::cout << "searching contacts ..." << std::endl;
	
	return ;
}