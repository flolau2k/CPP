/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:03:11 by flauer            #+#    #+#             */
/*   Updated: 2023/11/21 14:24:08 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
  }
  std::locale loc;
  std::string s;
  bool space_printed = false;
  for (int i = 1; i < argc; i++) {
    s = argv[i];
    for (std::string::size_type j = 0; j < s.length(); j++) {
		if (j == 0 && s[j] == ' ' && space_printed)
			continue;
      std::cout << std::toupper(s[j], loc);
    }
	space_printed = false;
	if (argv[i][std::string(argv[i]).length() - 1] != ' ')
	{
		space_printed = true;
    	std::cout << ' ';
	}
  }
  std::cout << std::endl;
  return (0);
}
