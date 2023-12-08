#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice &cpy);
  Ice &operator=(const Ice &);
  ~Ice();

  Ice *clone() const;
  void use(ICharacter &target);
};

#endif // ICE_H