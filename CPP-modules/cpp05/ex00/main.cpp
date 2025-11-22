#include "Bureaucrat.hpp"
#include <iostream>
#include <new>

int main() {
  try {
    std::cout << "\n===== Tests =====\n" << std::endl;

    std::cout << "----- Creation -----" << std::endl;
    Bureaucrat john("John", 75);
    std::cout << john << std::endl;

    std::cout << "\n----- Grade -----" << std::endl;
    john.incrementGrade();
    std::cout << john << std::endl;
    john.decrementGrade();
    std::cout << john << std::endl;

    std::cout << "\n----- Exception Tests -----" << std::endl;
    try {
      Bureaucrat high("Alice", 0);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }

    try {
      Bureaucrat low("Bob", 151);
      std::cout << low;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }

  } catch (const std::bad_alloc &e) {
    std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
