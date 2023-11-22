/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:44:53 by flauer            #+#    #+#             */
/*   Updated: 2023/11/22 09:53:01 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
  std::string _type;

public:
  Weapon(std::string type);
  ~Weapon();

  const std::string &getType(void) const;
  void setType(std::string type);
};

#endif