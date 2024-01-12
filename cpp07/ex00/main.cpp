#include "templates.hpp"
#include <iostream>

// int main(void) {
//   int a, b;
//   a = 1;
//   b = 3;

//   std::cout << "a is: " << a << ", b is: " << b << std::endl;
//   std::cout << "max is: " << max(a, b) << std::endl;
//   std::cout << "min is: " << min(a, b) << std::endl;
//   std::cout << "swapping..." << std::endl;
//   swap(a, b);
//   std::cout << "a is: " << a << ", b is: " << b << std::endl;
//   return 0;
// }

int main(void) {
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
  return 0;
}
