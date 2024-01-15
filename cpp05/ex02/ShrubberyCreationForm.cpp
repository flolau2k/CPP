#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

const std::string ShrubberyCreationForm::TREE = \
"     ^\n"
"    / \\\n"
"   /   \\\n"
"  /     \\\n"
" /_______\\\n"
"    ||\n"
"    ||\n"
"    ||";

ShrubberyCreationForm::ShrubberyCreationForm(
    const std::string &target /* = "home" */)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy)
    : AForm(cpy) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  AForm::operator=(other);
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::_execForm() const {
  std::ofstream out;
  out.open((getTarget() + "_shrubbery").c_str());
  out << TREE << std::endl;
  out.close();
}
