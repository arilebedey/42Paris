#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << _name << " FragTrap was created" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << _name << " FragTrap was created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
  _name = src._name;
  _hitPoints = src._hitPoints;
  _energyPoints = src._energyPoints;
  _attackDamage = src._attackDamage;
  std::cout << _name << " FragTrap was copied (copy constructor)" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  if (this != &other)
    ClapTrap::operator=(other);
  std::cout << _name << " FragTrap was copied (assignment operator)"
            << std::endl;
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << _name << " FragTrap was destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << this->_name << " is requesting a high five!"
            << std::endl;
}
