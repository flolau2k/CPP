#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : IMateriaSource {
public:
  MateriaSource();
  MateriaSource(const MateriaSource &cpy);
  MateriaSource &operator=(const MateriaSource &other);
  ~MateriaSource();

  void learnMateria(AMateria *m);
  AMateria* createMateria(std::string const &type);

private:
  const static int max_recipes = 4;
  AMateria *_recipes[max_recipes];
};

#endif // MATERIASOURCE_H