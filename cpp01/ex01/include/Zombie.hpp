/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:15:36 by flauer            #+#    #+#             */
/*   Updated: 2023/11/21 16:58:51 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
private:
  std::string _name;

public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();

  void announce(void) const;
  void set_name(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif
