#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap() {
  std::cout << DEFCONST << std::endl;
  _hp = 10;
  _ep = 10;
  _damage = 0;
  _name = "default ClapTrap";
}

ClapTrap::ClapTrap(const ClapTrap &C) { *this = C; }

ClapTrap::~ClapTrap() { std::cout << DESTRUCT << std::endl; }

ClapTrap &ClapTrap::operator=(const ClapTrap &C) {
  if (this != &C) {
    _hp = C._hp;
    _ep = C._ep;
    _damage = C._damage;
    _name = C._name;
  }
  return *this;
}

void ClapTrap::setName(const std::string &name) { _name = name; }

void ClapTrap::attack(const std::string &target) {
  if (_ep > 0) {
    std::cout << "ClapTrap " << _name << " attacks " << target << " causing "
              << std::to_string(_damage) << " points of damage!" << std::endl;
    --_ep;
  } else {
    std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hp -= amount;
  if (_hp <= 0)
    std::cout << "ClapTrap " << _name << " has 0 hitpoints left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_ep > 0) {
    --_ep;
    std::cout << "ClapTrap " << _name << " heals " << std::to_string(amount)
      << " of hitpoints!" << std::endl;
    _hp += amount;
  }
  else{
    std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
  }
}
