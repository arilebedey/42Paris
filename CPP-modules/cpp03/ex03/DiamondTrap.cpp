#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
    : ClapTrap("noname_clap_name"), ScavTrap(), FragTrap() {
  this->_name = "noname";
  std::cout << _name << " DiamondTrap was created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
  this->_name = name;
  this->_hitPoints = FragTrap::_hitPoints;
  this->_energyPoints = ScavTrap::_energyPoints;
  this->_attackDamage = FragTrap::_attackDamage;
  std::cout << _name << " DiamondTrap was created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
    : ClapTrap(src), ScavTrap(src), FragTrap(src) {
  this->_name = src._name;
  std::cout << _name << " DiamondTrap was copied (copy constructor)"
            << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  if (this != &other) {
    ClapTrap::operator=(other);
    FragTrap::operator=(other);
    ScavTrap::operator=(other);
    this->_name = other._name;
    std::cout << _name << " DiamondTrap was copied (assignment operator)"
              << std::endl;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << _name << " DiamondTrap was destroyed" << std::endl;
}

void DiamondTrap::whoAmI() {
  std::cout << "I am " << this->_name << " and my ClapTrap name is "
            << ClapTrap::_name << std::endl;
}
