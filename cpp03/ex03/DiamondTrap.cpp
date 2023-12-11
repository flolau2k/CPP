#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {
  std::cout << "DiamondTrap " << DEFCONST << std::endl;
  _hp = 100;
  _ep = 50;
  _damage = 30;
  ClapTrap::_name += "_clap_name";
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
  std::cout << "DiamondTrap " << NAMECONST << std::endl;
  _name = name;
  _hp = 100;
  _ep = 50;
  _damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &D) {
  std::cout << "DiamondTrap " << COPYCONST << std::endl;
  *this = D;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << DESTRUCT << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &D) {
  std::cout << "DiamondTrap " << COPYASSIGN << std::endl;
  if (this != &D) {
    _hp = D._hp;
    _ep = D._ep;
    _damage = D._damage;
    _name = D._name;
  }
  return *this;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
  std::cout << "I am DiamondTrap: " << _name
            << " with my ClapTrap Name: " << ClapTrap::_name << "\n"
            << "HP " << std::to_string(_hp) << "\n"
            << "EP " << std::to_string(_ep) << "\n"
            << "Damage " << std::to_string(_damage) << std::endl;
}
