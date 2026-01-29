#include "searchable_tree_bag.hpp"
#include "tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {};

searchable_tree_bag::~searchable_tree_bag() {};

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other)
    : tree_bag(other) {};

searchable_tree_bag &
searchable_tree_bag::operator=(const searchable_tree_bag &other) {
  tree_bag::operator=(other);
  return *this;
};

bool searchable_tree_bag::has(int val) const { return search_tree(val, tree); };

bool searchable_tree_bag::search_tree(int val, node *n) const {
  if (!n)
    return false;
  if (n->value == val)
    return true;
  if (val < n->value)
    return (search_tree(val, n->l));
  return (search_tree(val, n->r));
};
