#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm(const std::string &target = "home");
  ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();
  
private:
  void _execForm() const;
  static const std::string TREE;
};

#endif // SHRUBBERYCREATIONFORM_HPP