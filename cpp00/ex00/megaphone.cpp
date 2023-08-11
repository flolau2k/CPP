/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:03:11 by flauer            #+#    #+#             */
/*   Updated: 2023/08/11 13:47:05 by flauer           ###   ########.fr       */
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
  for (int i = 1; i < argc; i++) {
    s = argv[i];
    for (std::string::size_type j = 0; j < s.length(); j++) {
      std::cout << std::toupper(s[j], loc);
    }
    std::cout << ' ';
  }
  std::cout << std::endl;
  return (0);
}
