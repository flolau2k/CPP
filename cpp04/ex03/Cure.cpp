#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &cpy) : AMateria(cpy) {}

Cure &Cure::operator=(const Cure &other) { return *this; }

Cure::~Cure() {}

Cure *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
