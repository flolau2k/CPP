#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

#define DEFCONST "default constructor called"
#define COPYCONST "copy constructor called"
#define COPYASSIGN "Copy Assignment operator called"
#define DESTRUCT "Destructor called"

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