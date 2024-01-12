#include "Identify.hpp"
#include <iostream>

int main(void) {
  std::srand(std::time(NULL));
  Base *ptr = generate();
  while (ptr == NULL)
    ptr = generate();

  std::cout << "identifying ptr..." << std::endl;
  identify(ptr);
  std::cout << "identifying ref..." << std::endl;
  identify(*ptr);
  return 0;
}