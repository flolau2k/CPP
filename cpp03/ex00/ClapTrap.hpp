#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

#define DEFCONST "Default Constructor called"
#define COPYCONST "Copy Constructor called"
#define COPYASSIGN "Copy Assignment operator called"
#define NAMECONST "Name Constructor called"
#define DESTRUCT "Destructor called"

class ClapTrap {
public:
  ClapTrap();
  ClapTrap(const std::string &name);
  ClapTrap(const ClapTrap &C);
  ClapTrap &operator=(const ClapTrap &C);
  ~ClapTrap();

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void printStatus();

private:
  static int  count;
  int _hp;
  int _ep;
  int _damage;
  std::string _name;
};

#endif // CLAPTRAP_H
