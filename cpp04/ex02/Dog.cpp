#include "Dog.hpp"
#include <iostream>

Dog::Dog() : AAnimal() {
  std::cout << "Dog " << DEFCONST << std::endl;
  type = "Dog";
  brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other) {
  std::cout << "Dog " << COPYCONST << std::endl;
  *this = other;
}

Dog::~Dog() {
  std::cout << "Dog " << DESTRUCT << std::endl;
  delete brain;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog " << COPYASSIGN << std::endl;
  if (this != &other) {
    type = other.type;
    *(brain) = *(other.brain);
  }
  return *this;
}

void Dog::makeSound() const {
  std::cout << "woof" << std::endl;
}

void Dog::insertIdea(const std::string &idea, int idx) {
  brain->insertIdea(idea, idx);
}

const std::string &Dog::getIdea(int idx) const {
  return brain->getIdea(idx);
}
