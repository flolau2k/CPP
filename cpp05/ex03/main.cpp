#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  {
    Intern randomIntern;
    AForm *rrf;

    rrf = randomIntern.makeForm("robotomy request", "Bender");
    std::cout << "Form created: " << *rrf << std::endl;
    delete rrf;
  }

  {
    ShrubberyCreationForm form = ShrubberyCreationForm();
    std::cout << form << std::endl;
    std::cout << form.getTarget() << std::endl;
  }

  return 0;
}