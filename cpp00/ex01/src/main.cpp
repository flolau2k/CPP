/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:24:06 by flauer            #+#    #+#             */
/*   Updated: 2023/08/11 17:13:54 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void) {
  PhoneBook pb;
  std::string buf;

  std::cout << "Welcome to this wonderful PhoneBook!" << std::endl;
  while (true) {
    std::cout << "awaiting commands ..." << std::endl;
    std::cin >> buf;
    if (buf == "ADD")
		pb.AddContact();
	else if (buf == "SEARCH")
		pb.SearchContact();
	else if (buf == "EXIT")
		break;
	else
		std::cout << "invalid input!" << std::endl;
  }
  return (0);
}