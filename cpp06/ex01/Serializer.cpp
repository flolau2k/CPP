#include "Serializer.hpp"

std::ostream &operator<<(std::ostream &os, const Data &data) {
  os << "nb: " << data.nb << ", str: " << data.s;
  return(os);
}

uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}

Serializer::~Serializer() {}