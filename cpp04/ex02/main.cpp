#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void) {
  
  //AAnimal *k = new AAnimal();

  AAnimal *cat = new Cat();
  AAnimal *dog = new Dog();

  cat->makeSound();
  dog->makeSound();

  Cat *c = static_cast<Cat*>(cat);
  Cat *d = new Cat();

  c->insertIdea("gib mir whiskas!", 0);

  *d = *c;

  std::cout << d->getIdea(0) << std::endl;

  delete cat;
  delete dog;
  delete d;

  return 0;
}