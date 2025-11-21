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

  std::cout << "\n=== Deep Copy Behavior Test ===" << std::endl;

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
  alice->use(2, *eve);

  std::cout << "\n--- Copy constructing AliceCopy ---" << std::endl;
  Character aliceCopy(*alice);
  aliceCopy.use(0, *eve);
  aliceCopy.use(1, *eve);

  std::cout << "\n--- Modifying original ---" << std::endl;
  alice->unequip(0);
  alice->use(0, *eve);
  std::cout << "AliceCopy unaffected:" << std::endl;
  aliceCopy.use(0, *eve);

  delete eve;
  delete alice;
  delete src2;

  std::cout << "\n=== Program End ===" << std::endl;
  return 0;
}
