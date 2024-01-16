#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>

template <typename T>
int easyfind(T &haystack, int needle) {
  typename T::iterator it = std::find(haystack.begin(), haystack.end(), needle);
  if (it != haystack.end())
    return std::distance(haystack.begin(), it);
  return (-1);
}

#endif // EASYFIND_HPP