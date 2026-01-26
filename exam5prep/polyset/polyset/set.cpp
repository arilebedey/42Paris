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
