#include "AForm.hpp"
#include <iostream>

AForm::AForm(const std::string &name /* = "Random Form" */,
             int min_grade_sign /* = 100 */, int min_grade_exec /* = 70 */)
    : _name(name), _min_grade_sign(min_grade_sign),
      _min_grade_exec(min_grade_exec) {
  _signed = false;
}

AForm::AForm(const AForm &cpy)
    : _name(cpy._name), _signed(cpy._signed),
      _min_grade_sign(cpy._min_grade_sign),
      _min_grade_exec(cpy._min_grade_exec) {}

AForm &AForm::operator=(const AForm &other) {
  _signed = other._signed;
  return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }

bool AForm::getSigned() const { return _signed; }

int AForm::getMinGradeSign() const { return _min_grade_sign; }

int AForm::getMinGradeExec() const { return _min_grade_exec; }

const char *AForm::GradeTooLowException::what() const throw() {
  return "\033[1;31mGrade is too low for this Action!\033[0;39m";
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "\033[1;31mGrade is too high for this Action!\033[0;39m";
}

void AForm::beSigned(const Bureaucrat &B) {
  if (B.getGrade() > _min_grade_sign)
    throw GradeTooLowException();
  _signed = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &B) {
  out << "Form " << B.getName() << " is ";
  if (!B.getSigned())
    out << "not ";
  return out << "signed. \nMinimum grade to sign: " << B.getMinGradeSign()
             << "\nMinimum grade to exec: " << B.getMinGradeExec();
}