#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
  for (int i = 0; i < max_recipes; ++i) {
    _recipes[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource &cpy) { *this = cpy; }

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this != &other) {
    for (int i = 0; i < max_recipes; ++i) {
      if (_recipes[i])
        delete _recipes[i], _recipes[i] = NULL;
      if (other._recipes[i])
        _recipes[i] = other._recipes[i];
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < max_recipes; ++i) {
    if (_recipes[i])
      delete _recipes[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  for (int i = 0; i < max_recipes; ++i) {
    if (_recipes[i] == NULL) {
      _recipes[i] = m;
      return;
    }
  }
  std::cerr << "can't learn another Materia!" << std::cerr;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  AMateria *ret = NULL;
  for (int i = 0; i < max_recipes; ++i) {
    if (_recipes[i]->getType() == type) {
      ret = _recipes[i]->clone();
      break;
    }
  }
  return ret;
}
