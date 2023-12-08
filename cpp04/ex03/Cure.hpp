#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure : AMateria {
public:
  Cure();
  Cure(const Cure &other);
  Cure &operator=(const Cure &other);
  ~Cure();

  Cure *clone() const;
  void use(ICharacter &target);
};

#endif // CURE_H