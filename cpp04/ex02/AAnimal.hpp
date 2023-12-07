#ifndef AANIMAL_H
#define AANIMAL_H

#include <string>

#define DEFCONST "default constructor called"
#define COPYCONST "copy constructor called"
#define COPYASSIGN "Copy Assignment operator called"
#define DESTRUCT "Destructor called"

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