#ifndef CAT_H
#define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
public:
  Cat();
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);
  ~Cat();

  void makeSound() const;
  void insertIdea(const std::string &idea, int idx);
  const std::string &getIdea(int idx) const;

  private:
    Brain *brain;
};

#endif // CAT_H