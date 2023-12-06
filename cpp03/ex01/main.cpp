#include "ScavTrap.hpp"
#include <iostream>

int	main(void) {
  ScavTrap scav("Bob");
  std::cout << scav << std::endl;
  scav.attack("random chump");
  scav.takeDamage(10);
  std::cout << scav << std::endl;
  scav.beRepaired(5);
  std::cout << scav << std::endl;
  scav.beRepaired(5);
  std::cout << scav << std::endl;
  scav.guardGate();
  return 0;
}