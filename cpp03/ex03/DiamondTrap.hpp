#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  DiamondTrap();
  DiamondTrap(const DiamondTrap &D);
  DiamondTrap &operator=(const DiamondTrap &D);
  ~DiamondTrap();



};

#endif // DIAMONDTRAP_H