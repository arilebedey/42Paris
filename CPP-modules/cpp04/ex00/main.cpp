#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  std::cout << "\n===== Animal Tests  =====\n" << std::endl;

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
  Cat copyCat = *(Cat *)kitty;

  std::cout << "\n----- Destruction (polymorphic delete) -----" << std::endl;
  delete generic;
  delete doggy;
  delete kitty;

  std::cout << "\n===== WrongAnimal Tests  =====\n" << std::endl;

  std::cout << "----- Creation -----" << std::endl;
  const WrongAnimal *wrongCat = new WrongCat();

  std::cout << "\n----- Display types -----" << std::endl;
  std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;

  std::cout << "\n----- Sounds (Wrong) -----" << std::endl;
  wrongCat->makeSound();

  std::cout << "\n----- Destruction (Wrong) -----" << std::endl;
  delete wrongCat;

  std::cout << "\n===== End of WrongAnimal Tests  =====\n" << std::endl;

  std::cout << "----- copyDog & copyCat destruction -----" << std::endl;

  return 0;
}
