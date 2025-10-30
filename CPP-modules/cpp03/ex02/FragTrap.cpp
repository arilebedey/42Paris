#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
  this->_name = "noname";
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << "FragTrap default constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << "FragTrap constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
  std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  if (this != &other)
    ClapTrap::operator=(other);
  std::cout << "FragTrap assignment operator called for " << _name << std::endl;
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << this->_name << " is requesting a high five!"
            << std::endl;
}
