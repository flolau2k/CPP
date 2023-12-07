#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  ~Dog();

  void makeSound() const;
  void insertIdea(const std::string &idea, int idx);
  const std::string &getIdea(int idx) const;

private:
  Brain *brain;
};

#endif // DOG_H