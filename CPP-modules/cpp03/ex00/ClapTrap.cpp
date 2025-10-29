#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {
  _name = "ClapTrap";
  _hitPoints = 10;
  _energyPoints = 10;
  _attackDamage = 0;
  std::cout << _name << " was created" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) {
  _name = name;
  _hitPoints = 10;
  _energyPoints = 10;
  _attackDamage = 0;
  std::cout << _name << " was created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
  _name = src._name;
  _hitPoints = src._hitPoints;
  _energyPoints = src._energyPoints;
  _attackDamage = src._attackDamage;
  std::cout << _name << " was copied (copy constructor)" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
  if (this != &src) {
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
  }
  std::cout << _name << " was copied (assignment operator)" << std::endl;
  return *this;
}

ClapTrap::~ClapTrap() { std::cout << _name << " was destroyed" << std::endl; }

void ClapTrap::attack(const std::string &target) {
  if (!_energyPoints)
    std::cout << _name << " doesn't have any energy points and can't attack"
              << std::endl;
  else {
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacked " << target << " and dealt "
              << _attackDamage << " points of damage" << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints <= 0) {
    std::cout << "ClapTrap " << _name
              << " is already destroyed and can't take more damage"
              << std::endl;
    return;
  }
  if (amount > _hitPoints) {
    _hitPoints = 0;
    std::cout << "ClapTrap " << _name
              << " took fatal damage and now has 0 hit points" << std::endl;
  } else {
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " took " << amount
              << " points of damage and now has " << _hitPoints
              << " hit points left" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints <= 0) {
    std::cout << _name << " has no hit points left and can't do anything"
              << std::endl;
    return;
  }
  if (_energyPoints <= 0)
    std::cout << _name
              << " can't be repaired since it doesn't have enough energy points"
              << std::endl;
  else {
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " was healed with " << amount
              << " hit points. Now it has " << _hitPoints << " hit points"
              << std::endl;
  }
}
