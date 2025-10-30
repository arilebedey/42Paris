#include "ScavTrap.hpp"
#include <iostream>

int main() {
  std::cout << "----- Creation -----" << std::endl;
  ScavTrap a("Alpha");

  std::cout << "\n----- Attack with _attackDamage = 0 -----" << std::endl;
  a.attack("Enemy1");

  std::cout << "\n----- Healing -----" << std::endl;
  a.beRepaired(5);

  std::cout << "\n----- Sustaining damamge -----" << std::endl;
  a.takeDamage(3);

  std::cout << "\n----- Healing -----" << std::endl;
  a.beRepaired(2);

  std::cout << "\n----- Attack with _attackDamage = 0 -----" << std::endl;
  a.attack("Enemy2");

  std::cout << "\n----- Fatal damage -----" << std::endl;
  a.takeDamage(300);

  std::cout << "\n----- Act with _hitPoints = 0 -----" << std::endl;
  a.attack("Enemy3");

  std::cout << "\n----- Create b -----" << std::endl;
  ScavTrap b("Beta");

  std::cout << "\n----- Copy constructor b onto c -----" << std::endl;
  ScavTrap c(b);

  std::cout << "\n----- Assignment (operator=) b onto c -----" << std::endl;
  c = b;

  std::cout << "\n----- Deal c damage -----" << std::endl;
  b.takeDamage(8);

  std::cout << "\n----- Guard gate -----" << std::endl;
  b.guardGate();

  std::cout << std::endl;

  return 0;
}
