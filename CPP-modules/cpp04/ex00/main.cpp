#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  std::cout << "----- Creation -----" << std::endl;
  const Animal *generic = new Animal();
  const Animal *doggy = new Dog();
  const Animal *kitty = new Cat();

  std::cout << "\n----- Display types -----" << std::endl;
  std::cout << "generic type: " << generic->getType() << std::endl;
  std::cout << "doggy type: " << doggy->getType() << std::endl;
  std::cout << "kitty type: " << kitty->getType() << std::endl;

  std::cout << "\n----- Sounds -----" << std::endl;
  generic->makeSound();
  doggy->makeSound();
  kitty->makeSound();

  std::cout << "\n----- Copy and Assignment -----" << std::endl;
  Dog copyDog(*(Dog *)doggy);
  copyDog = *(Dog *)doggy;

  std::cout << "\n----- Destruction (polymorphic delete) -----" << std::endl;
  delete generic;
  delete doggy;
  delete kitty;

  std::cout << "\n===============================" << std::endl;
  std::cout << "=== WrongAnimal Test Begins ===" << std::endl;
  std::cout << "===============================\n" << std::endl;

  const WrongAnimal *wrongGeneric = new WrongAnimal();
  const WrongAnimal *wrongCat = new WrongCat();

  std::cout << "\n----- Display types (Wrong) -----" << std::endl;
  std::cout << "wrongGeneric type: " << wrongGeneric->getType() << std::endl;
  std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;

  std::cout << "\n----- Sounds (Wrong) -----" << std::endl;
  wrongGeneric->makeSound();
  wrongCat->makeSound();

  std::cout << "\n----- Direct call WrongCat -----" << std::endl;
  WrongCat directWrongCat;
  directWrongCat.makeSound();

  std::cout << "\n----- Destruction (Wrong) -----" << std::endl;
  delete wrongGeneric;
  delete wrongCat;

  std::cout << "\n=== End of Tests ===" << std::endl;
  return 0;
}
