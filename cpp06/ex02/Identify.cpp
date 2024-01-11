#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
  int x = std::rand() + 1 / ((RAND_MAX + 1u) / 3);
  switch (x) {
    case 1:
      return new A();
    case 2:
      return new B();
    case 3:
      return new C();
  }
  return NULL;
}

void identify(Base *p) {
  if (dynamic_cast<A*>(p) != NULL)
    std::cout << "A!" << std::endl;
  else if (dynamic_cast<B*>(p) != NULL)
    std::cout << "B!" << std::endl;
  else if (dynamic_cast<C*>(p) != NULL)
    std::cout << "C!" << std::endl;
  else
    std::cout << "bad!" << std::endl;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A!" << std::endl;
  } catch (std::exception &e) {}
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B!" << std::endl;
  } catch (std::exception &e) {}
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C!" << std::endl;
  } catch (std::exception &e) {}
}