#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  {
    AForm *form = new ShrubberyCreationForm("here");
    Bureaucrat hans("Hans", 137);

    std::cout << *form << std::endl;
    std::cout << hans << std::endl;

    hans.signForm(*form);
    std::cout << *form << std::endl;

    hans.executeForm(*form);
    delete form;
  }
  {
    RobotomyRequestForm form("marvin");
    Bureaucrat vogon("some random vogon", 42);

    std::cout << form << std::endl;
    std::cout << vogon << std::endl;

    vogon.signForm(form);
    vogon.executeForm(form);
  }
  {
    PresidentialPardonForm form("marvin");
    Bureaucrat supervisor("vogon supervisor", 5);

    supervisor.signForm(form);
    supervisor.executeForm(form);
  }

  return 0;
}