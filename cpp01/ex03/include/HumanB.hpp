/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:45:21 by flauer            #+#    #+#             */
/*   Updated: 2023/11/22 09:50:24 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <string>

class HumanB {
private:
  std::string _name;
  Weapon *_weapon;

public:
  HumanB(std::string name);
  ~HumanB();
  void attack();
  void setWeapon(Weapon &weapon);
};

#endif
