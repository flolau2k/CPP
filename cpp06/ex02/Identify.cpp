#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
  int x = std::rand() % 3;
  std::cout << "x is: " << x << std::endl;
  if (x % 3 == 0) return new A();
  else if (x % 3 == 1) return new B();
  else return new C();
}

void identify(Base *p) {
  if (dynamic_cast<A*>(p) != NULL)
    std::cout << "A!" << std::endl;
  else if (dynamic_cast<B*>(p) != NULL)
    std::cout << "B!" << std::endl;
  else if (dynamic_cast<C*>(p) != NULL)
    std::cout << "C!" << std::endl;
  else
    std::cout << "None of A, B or C!" << std::endl;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A!" << std::endl;
    return;
  } catch (std::exception &e) {}
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B!" << std::endl;
    return;
  } catch (std::exception &e) {}
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C!" << std::endl;
    return;
  } catch (std::exception &e) {}
  std::cout << "None of A, B or C!" << std::endl;
  return;
}