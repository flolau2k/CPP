#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
  std::cout << "WrongAnimal " << DEFCONST << std::endl;
  type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  std::cout << "WrongAnimal " << COPYCONST << std::endl;
  type = other.type;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal " << DESTRUCT << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal " << COPYASSIGN << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << " * wild WrongAnimal noises * " << std::endl;
}

const std::string &WrongAnimal::getType() const {
  return type;
}
