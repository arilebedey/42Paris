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
  int lvl = -1;

  if (level == "DEBUG")
    lvl = 0;
  else if (level == "INFO")
    lvl = 1;
  else if (level == "WARNING")
    lvl = 2;
  else if (level == "ERROR")
    lvl = 3;

  switch (lvl) {
  case 0:
    this->debug();
    break;
  case 1:
    this->info();
    this->debug();
    break;
  case 2:
    this->warning();
    this->info();
    this->debug();
    break;
  case 3:
    this->warning();
    this->info();
    this->debug();
    this->error();
    break;
  default:
    std::cout << "*Birds flying high, you know how I feel...*" << std::endl;
  }
}
