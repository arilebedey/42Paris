#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  try {
    // subject test
    std::cout << "\nSubject's test:" << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // int limits
    Span small(2);
    small.addNumber(std::numeric_limits<int>::min());
    small.addNumber(std::numeric_limits<int>::max());

    std::cout << "\nInt limits Span test:" << std::endl;
    std::cout << "Shortest span: " << small.shortestSpan() << std::endl;
    std::cout << "Longest span: " << small.longestSpan() << std::endl;

    // single value in span
    std::cout << "\nSingle value Span test:" << std::endl;
    try {
      Span single(200);
      single.addNumber(std::numeric_limits<int>::min());

      std::cout << "Shortest span: " << single.shortestSpan() << std::endl;
      std::cout << "Longest span: " << single.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }

    // large test with addRange
    std::cout << "\nMillion values added with addRange test:" << std::endl;
    Span span(1000000);
    // Span span(999999);

    std::srand(std::time(nullptr));
    std::list<int> random_values;
    for (int i = 0; i < 1000000; ++i) {
      random_values.push_back(std::rand());
    }

    span.addRange(random_values.begin(), random_values.end());

    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;

    return 0;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 0;
  }
}
