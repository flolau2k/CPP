#include "Form.hpp"
#include <iostream>

int main(void) {
  Form f("Passierschein A38", 10, 30);

  std::cout << f << std::endl;

  Bureaucrat hans("Hans", 42);
  hans.signForm(f);

  Bureaucrat wil("Wilhelm", 2);
  wil.signForm(f);

  std::cout << f << std::endl;

  wil.signForm(f);

  std::cout << f << std::endl;

  // a.incrementGrade();
  // std::cout << a;

  // try {
  //   b.incrementGrade();
  // } catch (std::exception &e) {
  //   std::cerr << e.what() << std::endl;
  // }

  // try {
  //   c.decrementGrade();
  // } catch (std::exception &e) {
  //   std::cerr << e.what() << std::endl;
  // }

  // std::cout << a << b << c;
  
  // try {
  //   Bureaucrat d("Otto", -1);
  // } catch (std::exception &e) {
  //   std::cerr << e.what() << std::endl;
  // }

  // try {
  //   Bureaucrat e("Karl", 151);
  // } catch (std::exception &e) {
  //   std::cerr << e.what() << std::endl;
  // }

  // return 0;
}