#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>

void Span::addNumber(int n) {
  if (_numbers.size() == _max_size) {
    throw std::runtime_error("Cannot add more numbers, span is full");
  }
  _numbers.push_back(n);
}

unsigned int Span::shortestSpan() {
  if (_numbers.size() < 2) {
    throw std::runtime_error("Not enough numbers to find a span");
  }
  std::list<int> sorted_numbers = _numbers;
  sorted_numbers.sort();
  unsigned int shortest = std::numeric_limits<unsigned int>::max();

  for (std::list<int>::iterator it = ++sorted_numbers.begin();
       it != sorted_numbers.end(); ++it) {
    std::list<int>::iterator prev = it;
    --prev;
    unsigned int span =
        static_cast<unsigned int>(*it) - static_cast<unsigned int>(*prev);
    if (span < shortest) {
      shortest = span;
    }
  }
  return shortest;
}

unsigned int Span::longestSpan() {
  if (_numbers.size() < 2) {
    throw std::runtime_error("Not enough numbers to find a span");
  }
  int min_val = *std::min_element(_numbers.begin(), _numbers.end());
  int max_val = *std::max_element(_numbers.begin(), _numbers.end());
  unsigned int diff =
      static_cast<unsigned int>(max_val) - static_cast<unsigned int>(min_val);
  return diff;
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _numbers = other._numbers;
    _max_size = other._max_size;
  }
  return *this;
}
