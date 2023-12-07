#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>
#include "ICharacter.hpp"

class AMateria {
public:
  AMateria(std::string const &type);
  AMateria(const AMateria &other);
  AMateria &operator=(const AMateria &other);
  ~AMateria();

  std::string const &getType() const;
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);

protected:
};

#endif // AMATERIA_H