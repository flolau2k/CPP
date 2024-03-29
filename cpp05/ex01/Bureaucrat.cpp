#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(
    const std::string &new_name /* = "Nameless Bureaucrat" */,
    int new_grade /* = 142 */)
    : name(new_name) {
  if (new_grade > 150)
    throw(GradeTooLowException());
  if (new_grade < 1)
    throw(GradeTooHighException());
  grade = new_grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
    : name(cpy.getName()), grade(cpy.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  grade = other.getGrade();
  return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade() {
  if (grade == 1)
    throw GradeTooHighException();
  --grade;
}

void Bureaucrat::decrementGrade() {
  if (grade == 150)
    throw GradeTooLowException();
  ++grade;
}

int Bureaucrat::getGrade() const { return grade; }

const std::string &Bureaucrat::getName() const { return name; }

std::ostream &operator<<(std::ostream &out, const Bureaucrat &B) {
  return out << B.getName() << ", bureaucrat grade " << B.getGrade()
             << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "\033[1;31mGrade cannot be any higher than 1!\033[0;39m";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "\033[1;31mGrade cannot be any lower than 150!\033[0;39m";
}

void Bureaucrat::signForm(Form &F) const {
  if (F.getSigned()) {
    std::cout << "Form " << F.getName() << " is already signed! abort..."
              << std::endl;
    return;
  }
  try {
    F.beSigned(*this);
    std::cout << name << " signed " << F.getName() << std::endl;
  } catch (const Form::GradeTooLowException &e) {
    std::cout << name << " couldn't sign " << F.getName()
              << " because his grade is too low." << std::endl;
  }
}
