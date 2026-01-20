#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other) {}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other) {
    tree_bag::operator=(other);
    return *this;
}

searchable_tree_bag::~searchable_tree_bag() {}  // Virtual destructor implementation

bool searchable_tree_bag::has(int val) const 
{
    return search_node(tree, val);
}

bool searchable_tree_bag::search_node(node *n, int val) const {
    if (!n)
        return false;
    if (n->value == val)
        return true;
    if (val < n->value)
        return search_node(n->l, val);
    return search_node(n->r, val);
}
