#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void pdf_test() {
  const Animal *cat = new Cat();
  const Animal *dog = new Dog();

  delete cat;
  delete dog;
}

void test_array() {
  Animal* arr[4];
  arr[0] = new Cat();
  arr[1] = new Dog();
  arr[2] = new Cat();
  arr[3] = new Dog();

  for (int i = 0; i < 4; ++i) {
    delete arr[i];
  }
}

void test_idea() {
  Cat tom;

  tom.insertIdea("catch mouse", 0);

  std::cout << tom.getIdea(0) << std::endl;
}

void test_deep_copy() {
  Cat tom;

  tom.insertIdea("catch mouse", 0);
  {
    Cat minny(tom);
  }
  std::cout << tom.getIdea(0) << std::endl;
  {
    Cat minny = tom;
  }
  std::cout << tom.getIdea(0) << std::endl;
}

int main(int argc, char **argv) {
  if (argc > 1)
  {
    std::string arg = argv[1];
    if (arg == "1") {
      pdf_test();
    }
    else if (arg == "2") {
      test_array();
    }
    else if (arg == "3") {
      test_idea();
    }
    else if (arg == "4") {
      test_deep_copy();
    }
    else {
      std::cerr << "unrecognized option." << std::endl;
    }
  }
  else {
    std::cerr << "please choose test [1 - 4]!" << std::endl;
  }
  return 0;
}