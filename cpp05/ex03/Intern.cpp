#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

const std::string Intern::forms[] = {
    "presidential pardon", "robotomy request", "shrubbery creation"};

Intern::Intern() {}

Intern::Intern(const Intern &cpy) {
  (void)cpy;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

AForm *Intern::makeForm(const std::string &name,
                        const std::string &target) const {
  int idx = -1;
  for (int i = 0; i < num_forms; ++i) {
    if (name == forms[i]) {
      idx = i;
      std::cout << "Intern creates " << forms[i] << std::endl;
      break;
    }
  }
  switch (idx) {
  case 0:
    return new PresidentialPardonForm(target);
  case 1:
    return new RobotomyRequestForm(target);
  case 2:
    return new ShrubberyCreationForm(target);
  default:
    std::cerr << "Intern cannot create Form: " << name
              << " because it does not exist!" << std::endl;
  }
  return 0;
}