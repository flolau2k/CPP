#ifndef PAIR_HPP
#define PAIR_HPP

template <typename T>
class Pair {
public:
  Pair(const T &first, const T &second) {
    if (first > second) {
      _upper = first;
      _lower = second;
    } else {
      _upper = second;
      _lower = first;
    }
  }

  Pair(const Pair &cpy) {
    *this = cpy;
  }

  Pair &operator=(const Pair &other) {
    if (this != &other) {
      _upper = other._upper;
      _lower = other._lower;
    }
    return *this;
  }

  ~Pair() {}

  T get_upper() const {
    return _upper;
  }

  T get_lower() const {
    return _lower;
  }

  bool operator<(const Pair &other) {
    return _upper < other._upper;
  }

  bool operator>(const Pair &other) {
    return other < *this;
  }

  bool operator<=(const Pair &other) {
    return !(*this > other);
  }

  bool operator>=(const Pair &otehr) {
    return !(*this < other);
  }

private:
  Pair() {}

  T _upper;
  T _lower;
};

#endif // PAIR_HPP