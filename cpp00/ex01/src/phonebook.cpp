/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:16:55 by flauer            #+#    #+#             */
/*   Updated: 2023/08/13 14:34:46 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void print_line(Contact &c)
{
	
}

PhoneBook::PhoneBook() 
{
	oldest = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::AddContact() {
	std::cout << "Add new Contact:" << std::endl; 
	contacts[oldest].fillContact();
	oldest++;
	if (oldest > MAX_CONTACTS)
		oldest = 0;
	return ;
}

void PhoneBook::SearchContact()
{
	std::cout << "|   IDX    | First    |Last      |  nick    |" << std::endl;

	
	return ;
}