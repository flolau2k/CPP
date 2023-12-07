#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  Cat tom;

  tom.insertIdea("catch mouse", 0);

  std::cout << tom.getIdea(0) << std::endl;

  const Animal *cat = new Cat();
  const Animal *dog = new Dog();

  delete cat;
  delete dog;

  return 0;
}