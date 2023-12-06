#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
  std::cout << "Animal " << DEFCONST << std::endl;
  type = "";
}

Animal::Animal(const Animal &other) {
  std::cout << "Animal " << COPYCONST << std::endl;
  type = other.type;
}

Animal::~Animal() {
  std::cout << "Animal " << DESTRUCT << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal " << COPYASSIGN << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

void Animal::makeSound() const {
  std::cout << " * wild animal noises * " << std::endl;
}

const std::string &Animal::getType() const {
  return type;
}
