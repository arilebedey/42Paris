#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
  std::cout << "=== Basic Subject Test ===" << std::endl;
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter *me = new Character("me");
  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter *bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;

  std::cout << "\n=== Extended Registry Pattern Tests ===" << std::endl;

  MateriaSource *src2 = new MateriaSource();
  src2->learnMateria(new Ice());
  src2->learnMateria(new Cure());

  Character *alice = new Character("Alice");
  Character *eve = new Character("Eve");

  AMateria *ice = src2->createMateria("ice");
  AMateria *cure = src2->createMateria("cure");
  alice->equip(ice);
  alice->equip(cure);

  alice->use(0, *eve);
  alice->use(1, *eve);

  std::cout << "\n--- Testing unequip and registry behavior ---" << std::endl;
  alice->unequip(1);
  alice->unequip(0);

  std::cout << "\n--- Re-equipping new materias ---" << std::endl;
  alice->equip(src2->createMateria("ice"));
  alice->equip(src2->createMateria("cure"));
  alice->use(0, *eve);
  alice->use(1, *eve);

  std::cout << "\n--- Testing invalid indices ---" << std::endl;
  alice->unequip(10);
  alice->use(10, *eve);

  std::cout << "\n--- Deep copy verification ---" << std::endl;
  Character copyAlice = *alice;
  copyAlice.use(0, *eve);

  delete eve;
  delete alice;
  delete src2;

  std::cout << "\n=== Shared External Materia Test ===" << std::endl;

  AMateria *sharedIce = new Ice();

  Character *cloud = new Character("Cloud");
  Character *tifa = new Character("Tifa");

  cloud->equip(sharedIce, false);
  tifa->equip(sharedIce, false);

  std::cout << ">>> Both using the same external Materia" << std::endl;
  cloud->use(0, *tifa);
  tifa->use(0, *cloud);

  std::cout << ">>> Tifa unequips the shared Materia (soft delete)"
            << std::endl;
  tifa->unequip(0);

  std::cout << ">>> Cloud continues to use it safely" << std::endl;
  cloud->use(0, *tifa);

  std::cout << ">>> Cleaning up Characters (will NOT delete sharedIce)"
            << std::endl;
  delete tifa;
  delete cloud;

  std::cout << ">>> Manually freeing sharedIce" << std::endl;
  delete sharedIce;

  std::cout << "\n=== Program End ===" << std::endl;

  return 0;
}
