#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm(const std::string &target = "home");
  PresidentialPardonForm(const PresidentialPardonForm &cpy);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();
  
private:
  void _execForm() const;
};

#endif // PRESIDENTIALPARDONFORM_HPP