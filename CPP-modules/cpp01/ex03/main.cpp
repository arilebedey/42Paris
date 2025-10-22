#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int main() {
  {
    std::cout << "=== The French Revolution Begins ===" << std::endl;

    Weapon guillotine("guillotine");
    Weapon musket("musket");

    HumanA robespierre("Robespierre", guillotine);
    HumanB danton("Danton");

    robespierre.attack();
    danton.attack();

    std::cout << "\n--- A new weapon for Danton ---" << std::endl;
    danton.setWeapon(musket);
    danton.attack();

    std::cout << "\n--- The weapons change ---" << std::endl;
    guillotine.setType("flaming guillotine");
    musket.setType("rusty musket");

    robespierre.attack();
    danton.attack();

    std::cout << "=== Liberté, égalité, fraternité ===" << std::endl;
  }

  return 0;
}
