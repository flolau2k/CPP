#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form {
public:
  Form(const std::string &name = "Random Form", int min_grade_sign = 100,
       int min_grade_exec = 70);
  Form(const Form &cpy);
  Form &operator=(const Form &other);
  ~Form();

  const std::string &getName() const;
  bool getSigned() const;
  int getMinGradeSign() const;
  int getMinGradeExec() const;

  void beSigned(const Bureaucrat &B);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  const std::string _name;
  bool _signed;
  const int _min_grade_sign;
  const int _min_grade_exec;
};

std::ostream &operator<<(std::ostream &out, const Form &B);

#endif // FORM_H