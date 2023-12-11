#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "defines.h"

class Animal {
public:
  Animal();
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  virtual ~Animal();

  virtual void makeSound() const;
  const std::string &getType() const;

protected:
  std::string type;
};

#endif // ANIMAL_H