#include "Form.hpp"
#include <iostream>

Form::Form(const std::string &name /* = "Random Form" */,
           int min_grade_sign /* = 100 */, int min_grade_exec /* = 70 */)
    : _name(name), _min_grade_sign(min_grade_sign),
      _min_grade_exec(min_grade_exec) {
  _signed = false;
}

Form::Form(const Form &cpy)
    : _name(cpy._name), _signed(cpy._signed),
      _min_grade_sign(cpy._min_grade_sign),
      _min_grade_exec(cpy._min_grade_exec) {}

Form &Form::operator=(const Form &other) {
  _signed = other._signed;
  return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return _name; }

bool Form::getSigned() const { return _signed; }

int Form::getMinGradeSign() const { return _min_grade_sign; }

int Form::getMinGradeExec() const { return _min_grade_exec; }

const char *Form::GradeTooLowException::what() const throw() {
  return "\033[1;31mGrade is too low for this Action!\033[0;39m";
}

const char *Form::GradeTooHighException::what() const throw() {
  return "\033[1;31mGrade is too high for this Action!\033[0;39m";
}

void Form::beSigned(const Bureaucrat &B) {
  if (B.getGrade() > _min_grade_sign)
    throw GradeTooLowException();
  _signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &B) {
  out << "Form " << B.getName() << " is ";
  if (!B.getSigned())
    out << "not ";
  return out << "signed. \nMinimum grade to sign: " << B.getMinGradeSign()
             << "\nMinimum grade to exec: " << B.getMinGradeExec();
}
