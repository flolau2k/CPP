#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap();
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &S);
  ScavTrap &operator=(const ScavTrap &S);
  ~ScavTrap();

  void attack(const std::string &target);
  void guardGate() const;
};

#endif //SCAVTRAP_H