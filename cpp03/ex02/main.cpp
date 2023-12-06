#include "FragTrap.hpp"
#include <iostream>

int	main(void) {
  FragTrap frag("Bob");
  frag.attack("random chump");
  std::cout << frag << std::endl;
  frag.highFivesGuys();
  return 0;
}