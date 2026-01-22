#include "set.hpp"

set::set(searchable_bag &bag) : bag(bag) {}

set::set(const set &other) : bag(other.bag) {}

set &set::operator=(const set &other) {
    (void)other;
    return *this;
}

set::~set() {}

void set::insert(int val) {
    if (!bag.has(val))
        bag.insert(val);
}

void set::insert(int *array, int size) 
{
    for (int i = 0; i < size; i++)
        insert(array[i]);
}

void set::print() const {
    bag.print();
}

void set::clear() {
    bag.clear();
}

bool set::has(int val) const {
    return bag.has(val);
}

searchable_bag &set::get_bag() const {
    return bag;
}