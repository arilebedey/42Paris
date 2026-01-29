#include "searchable_array_bag.hpp"
#include "array_bag.hpp"

searchable_array_bag::searchable_array_bag() : array_bag() {}

searchable_array_bag::~searchable_array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &other)
    : array_bag(other) {}

searchable_array_bag &
searchable_array_bag::operator=(const searchable_array_bag &other) {
  array_bag::operator=(other);
  return *this;
}

bool searchable_array_bag::has(int val) const {
  return search_array(val, data, size);
}

bool searchable_array_bag::search_array(int val, int *data, int size) const {
  for (int i = 0; i < size; ++i) {
    if (data[i] == val)
      return true;
  }
  return false;
}
