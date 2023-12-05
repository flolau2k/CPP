#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
  ScavTrap scav("ScavTrap");
  ScavTrap &scav_ref = scav;
  ClapTrap &clap_ref = scav;
  scav.attack("random chump");
  scav_ref.attack("random");
  clap_ref.attack("chump");
  ScavTrap clap = scav;
  clap.guardGate();
  return 0;
}