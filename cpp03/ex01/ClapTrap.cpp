#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int ClapTrap::count = 0;

ClapTrap::ClapTrap() : _hp(10), _ep(10), _damage(0) {
  std::cout << "ClapTrap " << DEFCONST << std::endl;
  _name = std::string("ClapTrap ") + std::to_string(count++);
}

ClapTrap::ClapTrap(const std::string &name)
    : _hp(10), _ep(10), _damage(0), _name(name) {
  std::cout << "ClapTrap " << NAMECONST << std::endl;
  ++count;
}

ClapTrap::ClapTrap(const ClapTrap &C) {
  std::cout << "ClapTrap " << COPYCONST << std::endl;
  *this = C;
  ++count;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap" << DESTRUCT << std::endl;
  --count;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &C) {
  std::cout << "ClapTrap " << COPYASSIGN << std::endl;
  if (this != &C) {
    _hp = C._hp;
    _ep = C._ep;
    _damage = C._damage;
    _name = C._name;
  }
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (_hp == 0) {
    std::cout << "ClapTrap " << _name
              << " cannot attack because it has no HP left!" << std::endl;
  } else if (_ep > 0) {
    std::cout << "ClapTrap " << _name << " attacks " << target << " causing "
              << std::to_string(_damage) << " points of damage!" << std::endl;
    --_ep;
  } else {
    std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hp == 0) {
    std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
  } else {
    std::cout << "ClapTrap " << _name << " took " << std::to_string(amount)
              << " damage!" << std::endl;
    _hp -= amount;
    if (_hp <= 0) {
      _hp = 0;
      std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
    }
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hp == 0) {
    std::cout << "ClapTrap " << _name
              << " cannot be repaired because it has no HP left!" << std::endl;
  } else if (_ep > 0) {
    --_ep;
    std::cout << "ClapTrap " << _name << " repairs " << std::to_string(amount)
              << " of hitpoints!" << std::endl;
    _hp += amount;
  } else {
    std::cout << "ClapTrap " << _name
              << " cannot be repaired because it has no energy left!"
              << std::endl;
  }
}

const std::string &ClapTrap::getName() const { return _name; }

int ClapTrap::getHP() const { return _hp; }

int ClapTrap::getEP() const { return _ep; }

int ClapTrap::getDamage() const { return _damage; }

std::ostream &operator<<(std::ostream &out, const ClapTrap &C) {
  return out << C.getName() << " has:" << std::endl
             << "\t" << std::to_string(C.getHP()) << " Hit Points" << std::endl
             << "\t" << std::to_string(C.getEP()) << " Energy Points"
             << std::endl
             << "\t" << std::to_string(C.getDamage()) << " Attack damage";
}
