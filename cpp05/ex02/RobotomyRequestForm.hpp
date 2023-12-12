#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm(const std::string &target = "home");
  RobotomyRequestForm(const RobotomyRequestForm &cpy);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
  ~RobotomyRequestForm();
  
private:
  void _execForm() const;
};

#endif // ROBOTOMYREQUESTFORM_HPP