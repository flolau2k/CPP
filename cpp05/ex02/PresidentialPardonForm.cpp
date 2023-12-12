#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(
    const std::string &target /* = "home" */)
    : AForm("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &cpy)
    : AForm(cpy) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  AForm::operator=(other);
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::_execForm() const {
  std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
