/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:16:55 by flauer            #+#    #+#             */
/*   Updated: 2023/10/26 10:08:59 by flauer           ###   ########.fr       */
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

static void	print_element(const std::string &e)
{
	std::cout << "|";
	for (size_t i = e.length(); i < 10; i++)
		std::cout << " ";
	std::cout << e;
	return ;
}

static void	print_line(Contact &c, int id)
{
	std::string 		idstr, fn, ln, nick;
	std::stringstream	sstream;

	sstream << id;
	idstr = sstream.str();
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
	std::string			buf;
	int					id;
	std::stringstream	sstr;

	print_element("IDX");
	print_element("First");
	print_element("Last");
	print_element("Nick");
	std::cout << "|" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
		print_line(contacts[i], i);
	while (true)
	{
		buf = get_input("Print ID [0 - 7] (or exit with any other input): ");
		if (buf.length() == 1 && buf[0] >= '0' && buf[0] <= '7')
		{
			id = buf[0] - '0';
			contacts[id].printContact();
		}
		else
			break ;
	}
	return ;
}
