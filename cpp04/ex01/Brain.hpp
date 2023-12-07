#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain {
public:
  Brain();
  Brain(const Brain &other);
  Brain &operator=(const Brain &other);
  ~Brain();

  void insertIdea(const std::string &idea, int idx);
  const std::string &getIdea(int idx) const;

private:
  static const int  count = 100;
  std::string       ideas[count];
};

#endif // BRAIN_H