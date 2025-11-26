#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>

class Span {
private:
  std::list<int> _numbers;
  unsigned int _max_size;

public:
  Span(unsigned int n) : _max_size(n) {}
  Span(const Span &other)
      : _numbers(other._numbers), _max_size(other._max_size) {}
  Span &operator=(const Span &other);
  ~Span() {}
  void addNumber(int n);
  unsigned int shortestSpan();
  unsigned int longestSpan();
};

#endif
