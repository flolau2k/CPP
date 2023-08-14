/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:16:55 by flauer            #+#    #+#             */
/*   Updated: 2023/08/14 11:18:17 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void	trim_entry(std::string &s)
{
	if (s.length() > 10)
	{
		s = s.substr(0, 10);
		s[9] = '.';
	}
	return ;
}

static void print_element(const std::string &e)
{
	std::cout << "|";
	for (size_t i = e.length(); i < 10; i++)
		std::cout << " ";
	std::cout << e;
	return ;
}

static void print_line(Contact &c, int id)
{
	std::string idstr, fn, ln, nick;

	idstr = std::to_string(id);
	fn = c.get_firstname();
	ln = c.get_lastname();
	nick = c.get_nickname();
	trim_entry(fn);
	trim_entry(ln);
	trim_entry(nick);
	print_element(idstr);
	print_element(fn);
	print_element(ln);
	print_element(nick);
	std::cout << "|" << std::endl;
	return ;
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
	if (oldest >= MAX_CONTACTS)
		oldest = 0;
	return ;
}

void PhoneBook::SearchContact()
{
	std::string	buf;
	int			id;

	print_element("IDX");
	print_element("First");
	print_element("Last");
	print_element("Nick");
	std::cout << "|" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
		print_line(contacts[i], i);
	buf = Contact::get_input("Print ID: ");
	try
	{
		id = std::stoi(buf);
		if (id < 0 || id > MAX_CONTACTS - 1)
			throw std::invalid_argument("Index is out of Range!");
		contacts[id].printContact();
	}
	catch(const std::invalid_argument& ia)
	{
		std::cerr << "Invalid Argument: " << ia.what() << std::endl;
	}
	return ;
}
