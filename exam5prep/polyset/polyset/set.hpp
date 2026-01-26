#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

// a set is a container that stores only unique values
// we create this class to turn searchable_bag in a set
class set {
public:
  set(searchable_bag &bag);
  ~set();
  set(const set &other);
  set &operator=(const set &other);

  void insert(int);
  void insert(int *, int);
  void print() const;
  void clear();

  bool has(int i) const;

  searchable_bag &get_bag() const;

private:
  searchable_bag &_bag;
};

#endif
