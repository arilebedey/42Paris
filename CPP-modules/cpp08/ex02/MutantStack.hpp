#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  typedef std::stack<T> stack;
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::iterator const_iterator;

  MutantStack() : stack() {}
  MutantStack(const MutantStack &other) : stack(other) {}
  MutantStack &operator=(const MutantStack &other) {
    std::stack<T>::operator=(other);
    return *this;
  }
  ~MutantStack() {}

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }
};

#endif
