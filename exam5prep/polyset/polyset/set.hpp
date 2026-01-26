#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

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

private:
  searchable_bag &_bag;
};

#endif
