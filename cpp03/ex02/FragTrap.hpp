#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
  FragTrap();
  FragTrap(const FragTrap &F);
  FragTrap(const std::string &name);
  FragTrap &operator=(const FragTrap &F);
  ~FragTrap();

  void highFivesGuys() const;

private:

};