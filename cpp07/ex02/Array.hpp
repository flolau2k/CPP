#ifndef ARRAY_H
#define ARRAY_H

#include <cstdlib>

template <typename T>
class Array {
  public:
    Array();
    Array(size_t n);
    Array(const Array &cpy);
    Array &operator=(const Array &other);
    ~Array();

    T &operator[](size_t idx);
    size_t size() const;

    class ArrayIndexOutOfBoundsException : public std::exception {
    public:
      const char *what() const throw();
    };
    
  private:
    T *_array;
    size_t _size;
};

#include "Array.tpp"

#endif // ARRAY_H