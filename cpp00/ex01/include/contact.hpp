/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:16:52 by flauer            #+#    #+#             */
/*   Updated: 2023/08/14 11:02:48 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact {
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();
	~Contact();
	void fillContact();
	void printContact();
	std::string get_firstname();
	std::string get_lastname();
	std::string get_nickname();
	std::string get_phone();
	std::string get_secret();
	static std::string get_input(const std::string prompt = "input: ");
};

#endif
