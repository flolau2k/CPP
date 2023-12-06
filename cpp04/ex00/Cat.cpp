#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
  std::cout << "Cat " << DEFCONST << std::endl;
  type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat " << COPYCONST << std::endl;
}

Cat::~Cat() {
  std::cout << "Cat " << DESTRUCT << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat " << COPYASSIGN << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

void Cat::makeSound() const {
  std::cout << "meow" << std::endl;
}
