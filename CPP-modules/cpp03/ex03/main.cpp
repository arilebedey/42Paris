#include "DiamondTrap.hpp"
#include <iostream>

int main() {
  std::cout << "----- Creation -----" << std::endl;
  DiamondTrap a("Alpha");

  std::cout << "\n----- Attack with default _attackDamage -----" << std::endl;
  a.attack("Enemy1");

  std::cout << "\n----- Healing -----" << std::endl;
  a.beRepaired(5);

  std::cout << "\n----- Taking damage -----" << std::endl;
  a.takeDamage(20);

  std::cout << "\n----- Healing again -----" << std::endl;
  a.beRepaired(15);

  std::cout << "\n----- Performing attack again -----" << std::endl;
  a.attack("Enemy2");

  std::cout << "\n----- WhoAmI test -----" << std::endl;
  a.whoAmI();

  std::cout << "\n----- Fatal damage -----" << std::endl;
  a.takeDamage(300);

  std::cout << "\n----- Acts after destruction (no hit points) -----"
            << std::endl;
  a.attack("Enemy3");
  a.beRepaired(10);

  std::cout << "\n----- Create b -----" << std::endl;
  DiamondTrap b("Beta");

  std::cout << "\n----- Copy constructor b onto c -----" << std::endl;
  DiamondTrap c(b);

  std::cout << "\n----- Assignment (operator=) b onto c -----" << std::endl;
  c = b;

  std::cout << "\n----- Call whoAmI on b and c -----" << std::endl;
  b.whoAmI();
  c.whoAmI();

  std::cout << "\n----- Trigger inherited ability from ScavTrap (attack) -----"
            << std::endl;
  b.attack("Enemy4");

  std::cout << "\n----- Trigger FragTrap high-five inherited ability -----"
            << std::endl;
  b.highFivesGuys();

  std::cout << std::endl;

  return 0;
}
