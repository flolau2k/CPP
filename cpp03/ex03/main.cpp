#include "DiamondTrap.hpp"
#include <iostream>

int	main(void) {
  DiamondTrap diam("Bob");
  DiamondTrap c;
  std::cout << c<< std::endl;
  diam.attack("random chump");
  diam.whoAmI();
  std::cout << diam << std::endl;
  diam.highFivesGuys();
  diam.guardGate();
  return 0;
}