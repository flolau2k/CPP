#include "Identify.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void) {
  std::srand(std::time(NULL));
  Base *ptr = generate();

  std::cout << "identifying ptr..." << std::endl;
  identify(ptr);
  std::cout << "identifying ref..." << std::endl;
  identify(*ptr);
  delete (ptr);
  return 0;
}