#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {};

searchable_tree_bag::~searchable_tree_bag() {};

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other)
    : tree_bag(other) {};

searchable_tree_bag &
searchable_tree_bag::operator=(const searchable_tree_bag &other) {
  tree_bag::operator=(other);
  return *this;
}

bool searchable_tree_bag::has(int i) const { return search_node(tree, i); };

bool searchable_tree_bag::search_node(node *n, int val) const {
  if (!n)
    return false;
  if (n->value == val)
    return true;
  if (val < n->value)
    return (search_node(n->l, val));
  return (search_node(n->r, val));
}
