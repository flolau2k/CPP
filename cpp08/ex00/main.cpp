#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <iostream>

int main(void) {
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
  std::deque<int> deq(arr, arr + sizeof(arr) / sizeof(int));
  std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));
  std::cout << "easyfind vec 5: " << ::easyfind(vec, 5) << std::endl;
  std::cout << "easyfind deq 5: " << ::easyfind(deq, 5) << std::endl;
  std::cout << "easyfind lst 5: " << ::easyfind(lst, 5) << std::endl;
}