#include <stdint.h>

#include <iomanip>
#include <iostream>
#include <string>

#include "Serializer.hpp"

int main(void) {
  Data data;
  data.s = "Hallo Welt!";
  std::cout << "Data: " << data << std::endl;
  uintptr_t data_ptr = Serializer::serialize(&data);
  std::cout << "data_ptr as hex: \t" << std::hex << std::showbase << data_ptr
            << std::dec << "\nAddress of data object: " << &data << std::endl;
  Data *ptr;
  ptr = Serializer::deserialize(data_ptr);
  std::cout << "deserialized data ptr: \t" << ptr << std::endl;
  std::cout << "changing data through deserialized ptr..." << std::endl;
  ptr->s = "Bye!";
  std::cout << "changed data original obj: " << data
            << "\nchanged data through deserialized ptr: " << *ptr << std::endl;
  return 0;
}