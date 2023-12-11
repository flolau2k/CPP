#ifndef ANIMAL_H
#define ANIMAL_H

#include "defines.h"
#include <string>

class Animal {
public:
  Animal();
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  virtual ~Animal(); // call the Destructor of Cat / Dog even if referred to as
                     // an Animal *

  virtual void makeSound() const;
  const std::string &getType() const;

protected:
  std::string type;
};

#endif // ANIMAL_H