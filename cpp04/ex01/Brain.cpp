#include "Brain.hpp"

Brain::Brain() {}

Brain::Brain(const Brain &other) {
  *this = other;
}

Brain::~Brain() {}

Brain &Brain::operator=(const Brain &other) {
  if (this != &other) {
    for (int i = 0; i < count; ++i) {
      ideas[i] = other.ideas[i];
    }
  }
  return *this;
}

void Brain::insertIdea(const std::string &idea, int idx) {
  ideas[idx] = idea;
}

const std::string &Brain::getIdea(int idx) const {
  return ideas[idx];
}
