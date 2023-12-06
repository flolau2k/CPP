#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
  std::cout << "Dog " << DEFCONST << std::endl;
  type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog " << COPYCONST << std::endl;
}

Dog::~Dog() {
  std::cout << "Dog " << DESTRUCT << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog " << COPYASSIGN << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

void Dog::makeSound() const {
  std::cout << "woof" << std::endl;
}
