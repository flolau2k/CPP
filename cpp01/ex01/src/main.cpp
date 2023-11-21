/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:59:24 by flauer            #+#    #+#             */
/*   Updated: 2023/11/21 16:58:36 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void) {
  Zombie *horde = zombieHorde(5, "Fred");
  for (int i = 0; i < 5; i++) {
    horde[i].announce();
  }
  delete[] horde;
  return (0);
}
