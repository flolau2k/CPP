#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) {
  _type = type;
}

AMateria::AMateria(const AMateria &other) {
  *this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

AMateria::~AMateria() {}

const std::string &AMateria::getType() const {
  return _type;
}

void AMateria::use(ICharacter &) {
  std::cerr << "abstract use not implemented!" << std::endl;
}
