#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
  std::cout << "WrongCat " << DEFCONST << std::endl;
  type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "WrongCat " << COPYCONST << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat " << DESTRUCT << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "WrongCat " << COPYASSIGN << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "meow" << std::endl;
}
