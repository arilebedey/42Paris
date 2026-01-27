#include "set.hpp"
#include "searchable_bag.hpp"

// no default constructor because _bag needs to be initialized

// constructor needs `bag` as reference since abstract class
// searchable_bag cannot be copied by value or intanciated
set::set(searchable_bag &bag) : _bag(bag) {};

set::~set() {};

set::set(const set &other) : _bag(other._bag) {};

// references can only be initialized once, hence no reassignment
set &set::operator=(const set &other) {
  (void)other;
  return *this;
};

void set::insert(int val) {
  if (!_bag.has(val))
    _bag.insert(val);
}

void set::insert(int *array, int size) {
  for (int i = 0; i < size; ++i)
    insert(array[i]);
}

void set::print() const { _bag.print(); };

void set::clear() { _bag.clear(); };

bool set::has(int i) const { return _bag.has(i); };

searchable_bag &set::get_bag() const { return _bag; };
