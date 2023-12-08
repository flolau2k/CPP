#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice &cpy);
  Ice &operator=(const Ice &other);
  ~Ice();

  Ice *clone() const;
  void use(ICharacter &target);
};

#endif // ICE_H