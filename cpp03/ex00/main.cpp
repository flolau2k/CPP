#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
  ClapTrap c1, c2, c3;

  c1.attack("some random bug");
  c2.attack("some random bug");
  c3.attack("some random bug");

  ClapTrap clap("clap"), track("track"), snap("snap");
  std::cout << clap << std::endl;
  clap.attack("some other bug");
  snap.attack("some other bug");
  track.attack("some other bug");
  clap.attack("some other bug");
  clap.attack("some other bug");
  clap.attack("some other bug");
  clap.attack("some other bug");
  clap.attack("some other bug");
  clap.attack("some other bug");
  clap.beRepaired(100);
  clap.takeDamage(200);
  std::cout << clap << std::endl;
  clap.beRepaired(100);
  clap.attack("some other bug");
  clap.attack("some other bug");
  clap.attack("some other bug");
  std::cout << clap << std::endl;

  return 0;
}