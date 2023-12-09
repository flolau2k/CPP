#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
  Bureaucrat a("Wilhelm", 10);
  Bureaucrat b("Friedrich", 1);
  Bureaucrat c("Hans", 150);

  std::cout << a << b << c;

  a.incrementGrade();
  std::cout << a;

  try {
    b.incrementGrade();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    c.decrementGrade();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << a << b << c;
  
  try {
    Bureaucrat d("Otto", -1);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat e("Karl", 151);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}