#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
    : ClapTrap("noname_clap_name"), ScavTrap(), FragTrap() {
  this->_name = "noname";
  std::cout << "DiamondTrap default constructor called for " << _name
            << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
  this->_name = name;
  this->_hitPoints = FragTrap::_hitPoints;
  this->_energyPoints = ScavTrap::_energyPoints;
  this->_attackDamage = FragTrap::_attackDamage;
  std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
    : ClapTrap(src), ScavTrap(src), FragTrap(src) {
  this->_name = src._name;
  std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
  if (this != &rhs) {
    ClapTrap::operator=(rhs);
    FragTrap::operator=(rhs);
    ScavTrap::operator=(rhs);
    this->_name = rhs._name;
    std::cout << "DiamondTrap assignment operator called for " << _name
              << std::endl;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::whoAmI() {
  std::cout << "I am " << this->_name << " and my ClapTrap name is "
            << ClapTrap::_name << std::endl;
}
