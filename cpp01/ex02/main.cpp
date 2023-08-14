/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:12:50 by flauer            #+#    #+#             */
/*   Updated: 2023/08/14 17:37:28 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Address of string: " << &str << std::endl
		<< "Address of stringPTR: " << stringPTR << std::endl
		<< "Address of stringREF: " << &stringREF << std::endl;

	std::cout << "Value of string: " << str << std::endl
		<< "Value of stringPTR: " << *stringPTR << std::endl
		<< "Value of stringREF: " << stringREF << std::endl;

	return (0);
}
