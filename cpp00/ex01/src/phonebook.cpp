/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:16:55 by flauer            #+#    #+#             */
/*   Updated: 2023/08/11 16:45:36 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() { this->oldest = 0; }

PhoneBook::~PhoneBook() {}

// bool PhoneBook::AddContact() { return true; }
void PhoneBook::AddContact() {
	std::cout << "Add new Contact:" << std::endl; 
	this->contacts[this->oldest].fill_contact()
}