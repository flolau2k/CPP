#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &cpy) : AMateria(cpy) {}

Ice &Ice::operator=(const Ice &other) { return *this; }

Ice::~Ice() {}

Ice *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
