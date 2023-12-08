#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(const Cure &cpy);
  Cure &operator=(const Cure &);
  ~Cure();

  Cure *clone() const;
  void use(ICharacter &target);
};

#endif // CURE_H