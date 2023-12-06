#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
  FragTrap();
  FragTrap(const FragTrap &F);
  FragTrap(const std::string &name);
  FragTrap &operator=(const FragTrap &F);
  ~FragTrap();

  void highFivesGuys() const;
};

#endif // FRAGTRAP_H