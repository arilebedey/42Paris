#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  try {
    Span sp(1000000);

    std::srand(std::time(nullptr));
    for (int i = 0; i < 1000000; ++i) {
      sp.addNumber(std::rand());
    }

    std::cout << "Million values test:" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    // int limits
    Span small(2);
    small.addNumber(std::numeric_limits<int>::min());
    small.addNumber(std::numeric_limits<int>::max());

    std::cout << "\nInt limits Span test:" << std::endl;
    std::cout << "Shortest span: " << small.shortestSpan() << std::endl;
    std::cout << "Longest span: " << small.longestSpan() << std::endl;

    // single value in span
    Span single(200);
    single.addNumber(std::numeric_limits<int>::min());

    std::cout << "\nSingle value Span test:" << std::endl;
    std::cout << "Shortest span: " << single.shortestSpan() << std::endl;
    std::cout << "Longest span: " << single.longestSpan() << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
