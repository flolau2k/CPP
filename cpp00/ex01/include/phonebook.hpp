/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:16:50 by flauer            #+#    #+#             */
/*   Updated: 2023/08/14 10:20:55 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define MAX_CONTACTS 8

#include "contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
private:
	Contact contacts[MAX_CONTACTS];
	int oldest;

public:
	PhoneBook();
	~PhoneBook();
	void AddContact();
	void SearchContact();
};

#endif