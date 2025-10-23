#include "Harl.hpp"
#include <ostream>

Harl::Harl(void) { std::cout << "A Harl materialized!" << std::endl; }

Harl::~Harl(void) { std::cout << "Harl ran away!" << std::endl; }

void Harl::debug(void) {
  std::cout << "I love to get extra bacon for my ";
  std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
  std::cout << "I really do!" << std::endl;
}

void Harl::info(void) {
  std::cout << "I cannot believe adding extra bacon costs more money. ";
  std::cout << "You didin’t put enough!  If you did, I wouldn’t be asking ";
  std::cout << "for more!" << std::endl;
}

void Harl::warning(void) {
  std::cout << "I think I deserve to have some extra bacon for free. ";
  std::cout << "I’ve been coming here for years, whereas you just started ";
  std::cout << "working here last month." << std::endl;
}

void Harl::error(void) {
  std::cout << "This is unacceptable! I want to speak to the manager now.";
  std::cout << std::endl;
}

void Harl::filter(std::string level) {
  void (Harl::*complain_fns[4])(void) = {&Harl::debug, &Harl::info,
                                         &Harl::warning, &Harl::error};
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  int i = 0;
  int found = 0;
  while (i < 4) {
    if (levels[i] == level) {
      found = 1;
      i++;
      break;
    }
    i++;
  }
  if (found) {
    for (int j = 0; j < i; j++)
      (this->*complain_fns[j])();
  } else {
    std::cout << "*Birds flying high, you know how I feel...*";
    std::cout << std::endl;
  }
}
