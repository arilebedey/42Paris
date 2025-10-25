#include "ClapTrap.hpp"

int main() {
  std::cout << "----- Création -----" << std::endl;
  ClapTrap a("Alpha");

  std::cout << "\n----- Attaque normale -----" << std::endl;
  a.attack("Enemy1");

  std::cout << "\n----- Réparation -----" << std::endl;
  a.beRepaired(5);

  std::cout << "\n----- Prendre des dégâts -----" << std::endl;
  a.takeDamage(3);

  std::cout << "\n----- Réparer à nouveau -----" << std::endl;
  a.beRepaired(2);

  std::cout << "\n----- Vider l'énergie -----" << std::endl;
  for (int i = 0; i < 10; ++i)
    a.attack("Training Dummy");

  std::cout << "\n----- Essayer d'attaquer sans énergie -----" << std::endl;
  a.attack("Enemy2");

  std::cout << "\n----- Essayer de se réparer sans énergie -----" << std::endl;
  a.beRepaired(1);

  std::cout << "\n----- Recevoir des dégâts fatals -----" << std::endl;
  a.takeDamage(100);

  std::cout << "\n----- Essayer d'agir en étant mort -----" << std::endl;
  a.attack("Enemy3");
  a.beRepaired(10);

  std::cout << "\n----- Constructeur de copie -----" << std::endl;
  ClapTrap b(a); // Devrait copier l'état de a (qui est mort)

  std::cout << "\n----- Création d'un autre ClapTrap -----" << std::endl;
  ClapTrap c("Charlie");

  std::cout << "\n----- Affectation (operator=) -----" << std::endl;
  c = a; // c devient comme a

  std::cout << "\n----- Tester 'c' après l’affectation -----" << std::endl;
  c.attack("Enemy4");

  std::cout << "\n----- Fin du programme -----" << std::endl;
  return 0;
}
