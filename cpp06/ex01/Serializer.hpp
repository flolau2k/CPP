#include <stdint.h>
#include <iostream>

typedef struct s_data {
  std::string s;
} Data;

std::ostream &operator<<(std::ostream &os, const Data &data);

class Serializer {
public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

private:
  Serializer();
  Serializer(const Serializer &cpy);
  Serializer &operator=(const Serializer &other);
  ~Serializer();

};