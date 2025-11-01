#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  std::cout << _name << " ScavTrap was created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  std::cout << _name << " ScavTrap was created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
  _name = src._name;
  _hitPoints = src._hitPoints;
  _energyPoints = src._energyPoints;
  _attackDamage = src._attackDamage;
  std::cout << _name << " ScavTrap was copied (copy constructor)" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  if (this != &other)
    ClapTrap::operator=(other);
  std::cout << _name << " ScavTrap was copied (assignment operator)"
            << std::endl;
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << _name << " ScavTrap was destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (!_energyPoints)
    std::cout << _name << " doesn't have any energy points and can't attack"
              << std::endl;
  else {
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacked " << target << " and dealt "
              << _attackDamage << " points of damage" << std::endl;
  }
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode."
            << std::endl;
}
