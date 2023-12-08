#include "Character.hpp"
#include <iostream>

Character::Character(const std::string &name) {
  _name = name;
  for (int i = 0; i < inventory_size; ++i) {
    inventory[i] = NULL;
    dropped[i] = NULL;
  }
}

Character::Character(const Character &cpy) { *this = cpy; }

Character &Character::operator=(const Character &other) {
  if (this != &other) {
    _name = other._name;
    for (int i = 0; i < inventory_size; ++i) {
      if (inventory[i])
        delete inventory[i], inventory[i] = NULL;
      if (other.inventory[i])
        inventory[i] = other.inventory[i]->clone();
    }
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < inventory_size; ++i) {
    if (inventory[i])
      delete inventory[i];
    if (dropped[i])
      delete dropped[i];
  }
}

void Character::dropMateria(AMateria *m) {
  for (int i = 0; i < inventory_size; ++i) {
    if (dropped[i] == NULL) {
      dropped[i] = m;
      return;
    }
  }
  delete dropped[0];
  for (int i = 0; i < inventory_size - 1; --i) {
    dropped[i] = dropped[i + 1];
  }
  dropped[inventory_size - 1] = m;
}

void Character::equip(AMateria *m) {
  if (!m)
    return;
  for (int i = 0; i < inventory_size; ++i) {
    if (inventory[i] == NULL) {
      inventory[i] = m;
      return;
    }
  }
  std::cerr << "Inventory is full!" << std::endl;
}

void Character::unequip(int idx) {
  if (idx >= inventory_size || idx < 0) {
    std::cerr << "index out of range!" << std::endl;
    return;
  }
  if (inventory[idx])
  {
    dropMateria(inventory[idx]);
    inventory[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= inventory_size || idx < 0) {
    std::cerr << "index out of range!" << std::endl;
    return;
  }
  if (inventory[idx])
    inventory[idx]->use(target);
}

const std::string &Character::getName() const { return _name; }
