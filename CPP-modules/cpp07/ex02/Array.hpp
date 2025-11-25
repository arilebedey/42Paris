#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T> class Array {
private:
  T *_array;
  size_t _size;

public:
  Array() : _array(NULL), _size(0) {}

  Array(unsigned int n) : _array(new T[n]()), _size(n) {}

  Array(const Array &other) {
    _size = other._size;
    if (other._size > 0) {
      _array = new T[other._size];
      for (size_t i = 0; i < other._size; ++i)
        _array[i] = other._array[i];
    } else {
      _array = NULL;
    }
  }

  ~Array() {
    delete[] _array;
    _array = NULL;
  }

  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] _array;
      _size = other._size;
      if (_size > 0) {
        _array = new T[_size];
        for (size_t i = 0; i < _size; ++i)
          _array[i] = other._array[i];
      } else {
        _array = NULL;
      }
    }
    return *this;
  }

  size_t size() const { return _size; }

  T &operator[](unsigned int index);

  const T &operator[](unsigned int index) const;
};

#include "Array.tpp"

#endif
