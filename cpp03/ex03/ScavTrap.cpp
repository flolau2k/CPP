#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "ScavTrap " << DEFCONST << std::endl;
  _damage = 20;
  _ep = 50;
  _hp = 100;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  std::cout << "ScavTrap " << NAMECONST << std::endl;
  _damage = 20;
  _ep = 50;
  _hp = 100;
}

ScavTrap::ScavTrap(const ScavTrap &S) {
  std::cout << "ScavTrap " << COPYCONST << std::endl;
  *this = S;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap" << DESTRUCT << std::endl; }

ScavTrap &ScavTrap::operator=(const ScavTrap &S) {
  std::cout << "ScavTrap " << COPYASSIGN << std::endl;
  if (this != &S) {
    _hp = S._hp;
    _ep = S._ep;
    _damage = S._damage;
    _name = S._name;
  }
  return *this;
}

void ScavTrap::attack(const std::string &target) {
  if (_hp == 0) {
    std::cout << "ScavTrap " << _name
              << " cannot attack because it has no HP left!" << std::endl;
  } else if (_ep > 0) {
    std::cout << "ScavTrap " << _name << " attacks " << target << " causing "
              << std::to_string(_damage) << " points of damage!" << std::endl;
    --_ep;
  } else {
    std::cout << "ScavTrap " << _name << " has no energy left!" << std::endl;
  }
}

void ScavTrap::guardGate() const {
  std::cout << "ScavTrap " << _name << " is now in GateKeeper Mode!"
            << std::endl;
}
