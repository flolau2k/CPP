#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>

class Bureaucrat {
public:
  Bureaucrat(const std::string &new_name = "Nameless Bureaucrat",
             int new_grade = 142);
  Bureaucrat(const Bureaucrat &cpy);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

  void incrementGrade();
  void decrementGrade();

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

#endif // BUREAUCRAT_H