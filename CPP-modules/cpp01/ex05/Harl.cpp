#include "Harl.hpp"

#include <iostream>

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug(void) {
  std::cout << "[DEBUG]" << std::endl;
  std::cout << "The user_id you are currently looking for could be in the ";
  std::cout << "`user` table." << std::endl;
}

void Harl::info(void) {
  std::cout << "[INFO]" << std::endl;
  std::cout << "We have 5 services running and they're even operational!";
  std::cout << std::endl;
}

void Harl::warning(void) {
  std::cout << "[WARNING]" << std::endl;
  std::cout << "A lot of cache is starting to build up on the VPS!";
  std::cout << std::endl;
}

void Harl::error(void) {
  std::cout << "[ERROR]" << std::endl;
  std::cout << "Why are there so many errors during CI?";
  std::cout << std::endl;
}

void Harl::complain(std::string level) {
  void (Harl::*complain_fns[4])(void) = {&Harl::debug, &Harl::info,
                                         &Harl::warning, &Harl::error};
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  for (int i = 0; i < 4; i++) {
    if (levels[i] == level) {
      (this->*complain_fns[i])();
      break;
    }
  }
}
