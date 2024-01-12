#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename A, typename Func>
void iter(A *array, size_t size, Func func) {
  for (size_t i = 0; i < size; i++) {
    func(array[i]);
  }
}

#endif // ITER_HPP