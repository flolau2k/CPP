#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
  DiamondTrap();
  DiamondTrap(const std::string &name);
  DiamondTrap(const DiamondTrap &D);
  DiamondTrap &operator=(const DiamondTrap &D);
  ~DiamondTrap();

  using ScavTrap::attack;
  void whoAmI() const;

private:
  std::string _name;
};

#endif // DIAMONDTRAP_H