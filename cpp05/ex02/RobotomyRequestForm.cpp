#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(
    const std::string &target /* = "home" */)
    : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy)
    : AForm(cpy) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  AForm::operator=(other);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::_execForm() const {
  std::cout << "VRRR VRRR VRRR ... ZZZZZZZZzzzzzzz\n";
  if (std::rand() % 2)
    std::cout << getTarget() << " has been robotomized." << std::endl;
  else
    std::cout << "attempted robotomy on " << getTarget() << " failed!"
              << std::endl;
}
