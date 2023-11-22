/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:53:02 by flauer            #+#    #+#             */
/*   Updated: 2023/11/22 10:42:58 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define DEBUG "DEBUG: Gathering dirty clothes"
#define INFO "INFO: Going to do the Laundry"
#define WARNING "WARNING: Found a penny in a Pocket!"
#define ERROR "ERROR: a brick found its way into the machine and it exploded"

class Harl {
private:
  const static std::string levels[4];
  void (Harl::*functions[4])(void) const;

  void debug(void) const;
  void info(void) const;
  void warning(void) const;
  void error(void) const;

public:
  Harl();
  ~Harl();
  void complain(std::string level);
};

#endif
