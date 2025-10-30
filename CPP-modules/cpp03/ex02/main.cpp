#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define BOLD "\033[1m"

void separator(const std::string &title) {
  std::cout << "\n"
            << BOLD << MAGENTA << "========== " << title
            << " ==========" << RESET << "\n"
            << std::endl;
}

int main() {
  separator("TEST DE CLAPTRAP");

  ClapTrap clap("Clappy");

  std::cout << BLUE << "ClapTrap attaque Bob !" << RESET << std::endl;
  clap.attack("Bob");

  std::cout << YELLOW << "ClapTrap subit 5 points de dégâts" << RESET
            << std::endl;
  clap.takeDamage(5);

  std::cout << GREEN << "ClapTrap se répare de 3 points" << RESET << std::endl;
  clap.beRepaired(3);

  separator("TEST DE SCAVTRAP");

  ScavTrap scav("Scavy");

  std::cout << BLUE << "ScavTrap attaque Alice !" << RESET << std::endl;
  scav.attack("Alice");

  std::cout << YELLOW << "ScavTrap subit 20 points de dégâts" << RESET
            << std::endl;
  scav.takeDamage(20);

  std::cout << GREEN << "ScavTrap se répare de 10 points" << RESET << std::endl;
  scav.beRepaired(10);

  std::cout << CYAN << "ScavTrap active le mode Gate Keeper" << RESET
            << std::endl;
  scav.guardGate();

  separator("TEST DE FRAGTRAP");

  FragTrap frag("Fraggy");

  std::cout << BLUE << "FragTrap attaque Eve !" << RESET << std::endl;
  frag.attack("Eve");

  std::cout << YELLOW << "FragTrap subit 30 points de dégâts" << RESET
            << std::endl;
  frag.takeDamage(30);

  std::cout << GREEN << "FragTrap se répare de 20 points" << RESET << std::endl;
  frag.beRepaired(20);

  std::cout << CYAN << "FragTrap demande un high five !" << RESET << std::endl;
  frag.highFivesGuys();

  separator("TEST DE POLYMORPHISME");

  ClapTrap *poly1 = new ScavTrap("PolyScav");
  ClapTrap *poly2 = new FragTrap("PolyFrag");

  std::cout << BLUE << "PolyScav attaque PolyFrag" << RESET << std::endl;
  poly1->attack("PolyFrag");

  std::cout << BLUE << "PolyFrag attaque PolyScav" << RESET << std::endl;
  poly2->attack("PolyScav");

  delete poly1;
  delete poly2;

  separator("FIN DES TESTS");

  return 0;
}
