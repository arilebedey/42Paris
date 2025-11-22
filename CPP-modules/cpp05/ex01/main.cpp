#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  try {
    std::cout << "\n----- Invalid Form Creation -----" << std::endl;
    try {
      Form invalidHigh("InvalidHigh", 0, 10);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }

    try {
      Form invalidLow("InvalidLow", 160, 10);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }

    std::cout << "\n----- << Form overload -----" << std::endl;
    Bureaucrat john("John", 50);
    Bureaucrat alice("Alice", 1);
    Form taxForm("TaxForm", 40, 20);

    std::cout << taxForm << std::endl;

    std::cout << "\n----- signForm -----" << std::endl;
    john.signForm(taxForm);
    std::cout << taxForm << std::endl;

    std::cout << "\n----- signForm -----" << std::endl;
    alice.signForm(taxForm);
    std::cout << taxForm << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Unexpected exception: " << e.what() << std::endl;
  }

  return 0;
}
