#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm {
public:
  AForm(const std::string &name = "Random Form", int min_grade_sign = 100,
        int min_grade_exec = 70, const std::string &target = "home");
  AForm(const AForm &cpy);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  const std::string &getName() const;
  const std::string &getTarget() const;
  bool getSigned() const;
  int getMinGradeSign() const;
  int getMinGradeExec() const;
  void beSigned(const Bureaucrat &B);
  void execute(const Bureaucrat &executor) const;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  class FormNotSignedException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  const std::string _name;
  const std::string _target;
  bool _signed;
  const int _min_grade_sign;
  const int _min_grade_exec;

  virtual void _execForm() const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &B);

#endif // AFORM_HPP