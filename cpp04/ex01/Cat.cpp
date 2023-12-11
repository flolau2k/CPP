#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
  std::cout << "Cat " << DEFCONST << std::endl;
  type = "Cat";
  brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat " << COPYCONST << std::endl;
  brain = new Brain();
  *this = other;
}

Cat::~Cat() {
  std::cout << "Cat " << DESTRUCT << std::endl;
  delete brain;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat " << COPYASSIGN << std::endl;
  if (this != &other) {
    type = other.type;
    *brain = *(other.brain);
  }
  return *this;
}

void Cat::makeSound() const {
  std::cout << "meow" << std::endl;
}

void Cat::insertIdea(const std::string &idea, int idx) {
  brain->insertIdea(idea, idx);
}

const std::string &Cat::getIdea(int idx) const {
  return brain->getIdea(idx);
}
