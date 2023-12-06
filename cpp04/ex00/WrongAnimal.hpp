#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

#define DEFCONST "default constructor called"
#define COPYCONST "copy constructor called"
#define COPYASSIGN "Copy Assignment operator called"
#define DESTRUCT "Destructor called"

class WrongAnimal {
public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal &operator=(const WrongAnimal &other);
  ~WrongAnimal();

  void makeSound() const;
  const std::string &getType() const;

protected:
  std::string type;
};

#endif // WRONGANIMAL_H