#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  Character(const std::string &name);
  Character(const Character &cpy);
  Character &operator=(const Character &other);
  ~Character();

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

private:
  static const int inventory_size = 4;
  std::string _name;
  AMateria *inventory[inventory_size];
  AMateria *dropped[inventory_size];

  void dropMateria(AMateria *m);
};

#endif // CHARACTER_H