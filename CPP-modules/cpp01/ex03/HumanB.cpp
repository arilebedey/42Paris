#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _weapon(NULL) {
  this->_name = name;
  std::cout << "HumanB " << name << " created with no weapon" << std::endl;
}

HumanB::~HumanB(void) {
  std::cout << "HumanB " << this->_name << " destroyed" << std::endl;
}

void HumanB::attack(void) {
  if (this->_weapon)
    std::cout << this->_name << " attacks with their "
              << this->_weapon->getType() << std::endl;
  else
    std::cout << this->_name << " has no weapon to attack with" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }
