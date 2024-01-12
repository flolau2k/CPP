#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
const char *Array<T>::ArrayIndexOutOfBoundsException::what() const throw() {
  return "\033[1;31mError: Array Index out of Bounds!\033[0;39m";
}

template <typename T>
Array<T>::Array() {
  _array = new T[0];
  _size = 0;
}

template <typename T>
Array<T>::Array(size_t n) {
  _array = new T[n];
  _size = n;
}

template <typename T>
Array<T>::Array(const Array<T> &cpy) {
  _size = cpy.size();
  _array = new T[_size];
  *this = cpy;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
  if (this != &other) {
    if (_size != other.size()) {
      _size = other.size();
      delete[] _array;
      _array = new T[_size];
    }
    for (size_t i = 0; i < _size; ++i) {
      _array[i] = other._array[i];
    }
  }
  return (*this);
}

template <typename T>
Array<T>::~Array() {
  delete[] _array;
}

template <typename T>
T &Array<T>::operator[](size_t idx) {
  if (idx >= this->size()) throw ArrayIndexOutOfBoundsException();
  return _array[idx];
}

template <typename T>
size_t Array<T>::size() const {
  return _size;
}

#endif // ARRAY_TPP
