#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug(void) {
  std::cout
      << "[DEBUG]" << std::endl
      << "The user_id you are currently looking for could be in the `user` "
         "table."
      << std::endl;
}

void Harl::info(void) {
  std::cout << "[INFO]" << std::endl
            << "We have 5 services running and they're even operational!"
            << std::endl;
}

void Harl::warning(void) {
  std::cout << "[WARNING]" << std::endl
            << "A lot of cache is starting to build up on the VPS!"
            << std::endl;
}

void Harl::error(void) {
  std::cout << "[ERROR]" << std::endl
            << "Why are there so many errors during CI?";
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
  case 1:
    this->info();
  case 2:
    this->warning();
  case 3:
    this->error();
    break;
  default:
    std::cout << "[Tirelessly analyzing your systems...]" << std::endl;
  }
}
