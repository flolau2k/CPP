#include <string>
#include <iostream>
#include "iter.hpp"

template <typename T>
void func(T &s) {
  std::cout << s << std::endl;
}

int main(void) {
  std::string arr[] = {"hallo", "welt", "adsf"};
  int arr2[] = {1, 2, 3, 4, 25, 3, 63};
  iter(arr, 3, func<std::string>);
  iter(arr2, 7, func<int>);
  return 0;
}
