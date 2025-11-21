#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <new>

int main() {
  try {
    std::cout << "\n===== Animal Tests  =====\n" << std::endl;

    std::cout << "----- Creation -----" << std::endl;
    const Animal *generic = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << "\n----- Display types -----" << std::endl;
    std::cout << "generic type: " << generic->getType() << std::endl;
    std::cout << "doggy type: " << dog->getType() << std::endl;
    std::cout << "kitty type: " << cat->getType() << std::endl;

    std::cout << "\n----- Sounds -----" << std::endl;
    generic->makeSound();
    dog->makeSound();
    cat->makeSound();

    std::cout << "\n----- Copy and Assignment -----" << std::endl;
    Dog copyDog = *(Dog *)dog;
    Cat copyCat = *(Cat *)cat;

    std::cout << "\n----- Destruction -----" << std::endl;
    delete generic;
    delete dog;
    delete cat;

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

  } catch (const std::bad_alloc &e) {
    std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
