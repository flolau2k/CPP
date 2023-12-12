#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm {
public:
  AForm(const std::string &name = "Random Form", int min_grade_sign = 100,
        int min_grade_exec = 70);
  AForm(const AForm &cpy);
  AForm &operator=(const AForm &other);
  ~AForm();

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

std::ostream &operator<<(std::ostream &out, const AForm &B);

#endif // AFORM_HPP