#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
    : _name(name), _weapon(weapon) {
  std::cout << "HumanA " << name << " created with ";
  std::cout << weapon.getType() << std::endl;
}

HumanA::~HumanA(void) {
  std::cout << "HumanA " << this->_name << " destroyed" << std::endl;
}

void HumanA::attack(void) {
  std::cout << this->_name << " attacks with their " << this->_weapon.getType()
            << std::endl;
}
