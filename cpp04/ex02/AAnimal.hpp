#ifndef AANIMAL_H
#define AANIMAL_H

#include <string>
#include "defines.h"

class AAnimal {
public:
  AAnimal();
  AAnimal(const AAnimal &other);
  AAnimal &operator=(const AAnimal &other);
  virtual ~AAnimal();

  virtual void makeSound() const = 0;
  const std::string &getType() const;

protected:
  std::string type;
};

#endif // AANIMAL_H