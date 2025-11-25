#include "Array.hpp"

template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index >= this->size())
    throw std::out_of_range("Array<T>: index out of range");
  return this->_array[index];
}

template <typename T> const T &Array<T>::operator[](unsigned int index) const {
  if (index >= this->size())
    throw std::out_of_range("Array<T>: index out of range");
  return this->_array[index];
}
