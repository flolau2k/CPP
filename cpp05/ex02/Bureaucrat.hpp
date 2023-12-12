#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>

class AForm;

class Bureaucrat {
public:
  Bureaucrat(const std::string &new_name = "Nameless Bureaucrat",
             int new_grade = 142);
  Bureaucrat(const Bureaucrat &cpy);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

  void incrementGrade();
  void decrementGrade();
  void signForm(AForm &F) const;
  void executeForm(const AForm &form) const;
  int getGrade() const;
  const std::string &getName() const;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  const std::string name;
  int grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &B);

#endif // BUREAUCRAT_HPP