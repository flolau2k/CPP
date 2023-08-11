/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:16:50 by flauer            #+#    #+#             */
/*   Updated: 2023/08/11 16:43:14 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"
#include <iostream>

class PhoneBook {
private:
  Contact contacts[8];
  int oldest;

public:
  PhoneBook();
  ~PhoneBook();
  void AddContact();
};

#endif