#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() {};

searchable_array_bag::~searchable_array_bag() {};

searchable_array_bag::searchable_array_bag(const searchable_array_bag &other)
    : array_bag(other) {};

searchable_array_bag &
searchable_array_bag::operator=(const searchable_array_bag &other) {
  array_bag::operator=(other);
  return *this;
}

bool searchable_array_bag::has(int val) const {
  return search_array(data, size, val);
};

bool searchable_array_bag::search_array(int *data, int size, int val) const {
  for (int i = 0; i < size; ++i) {
    if (data[i] == val)
      return true;
  }

  return false;
};
