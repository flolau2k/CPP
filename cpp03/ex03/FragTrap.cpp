#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "FragTrap " << DEFCONST << std::endl;
  _damage = 30;
  _ep = 100;
  _hp = 100;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  std::cout << "FragTrap " << NAMECONST << std::endl;
  _damage = 30;
  _ep = 100;
  _hp = 100;
}

FragTrap::FragTrap(const FragTrap &F) {
  std::cout << "FragTrap " << COPYCONST << std::endl;
  *this = F;
}

FragTrap::~FragTrap() { std::cout << "FragTrap" << DESTRUCT << std::endl; }

FragTrap &FragTrap::operator=(const FragTrap &F) {
  std::cout << "FragTrap " << COPYASSIGN << std::endl;
  if (this != &F) {
    _hp = F._hp;
    _ep = F._ep;
    _damage = F._damage;
    _name = F._name;
  }
  return *this;
}

void FragTrap::highFivesGuys() const {
  std::cout << "FragTrap " << _name << ": High Fives Guys ?!" << std::endl;
}
