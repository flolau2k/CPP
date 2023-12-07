#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() {
  std::cout << "AAnimal " << DEFCONST << std::endl;
  type = "";
}

AAnimal::AAnimal(const AAnimal &other) {
  std::cout << "AAnimal " << COPYCONST << std::endl;
  type = other.type;
}

AAnimal::~AAnimal() {
  std::cout << "AAnimal " << DESTRUCT << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
  std::cout << "AAnimal " << COPYASSIGN << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

const std::string &AAnimal::getType() const {
  return type;
}
