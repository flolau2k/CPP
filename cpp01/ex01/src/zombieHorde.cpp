/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:52:35 by flauer            #+#    #+#             */
/*   Updated: 2023/11/21 16:58:45 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  Zombie *ret = new Zombie[N];

  for (int i = 0; i < N; i++)
    ret[i].set_name(name);
  return ret;
}
