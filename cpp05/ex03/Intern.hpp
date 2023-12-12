#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
  Intern();
  Intern(const Intern &cpy);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm *makeForm(const std::string &name, const std::string &target) const;

private:
  const static int num_forms = 3;
  const static std::string forms[num_forms];
};

#endif // INTERN_HPP