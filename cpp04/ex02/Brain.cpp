#include "Brain.hpp"
#include <iostream>

Brain::Brain() { std::cout << "Brain " << DEFCONST << std::endl; }

Brain::Brain(const Brain &other) {
  std::cout << "Brain " << COPYCONST << std::endl;
  *this = other;
}

Brain::~Brain() { std::cout << "Brain " << DESTRUCT << std::endl; }

Brain &Brain::operator=(const Brain &other) {
  std::cout << "Brain " << COPYASSIGN << std::endl;
  if (this != &other) {
    for (int i = 0; i < count; ++i) {
      ideas[i] = other.ideas[i];
    }
  }
  return *this;
}

void Brain::insertIdea(const std::string &idea, int idx) { ideas[idx] = idea; }

const std::string &Brain::getIdea(int idx) const { return ideas[idx]; }
