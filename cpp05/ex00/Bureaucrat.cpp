#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &new_name, int new_grade)
    : name(new_name) {
  if (new_grade > 150)
    throw(GradeTooLowException());
  if (new_grade < 0)
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
  if (grade == 1) throw GradeTooHighException();
  --grade;
}

void Bureaucrat::decrementGrade() {
  if (grade == 150) throw GradeTooLowException();
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
