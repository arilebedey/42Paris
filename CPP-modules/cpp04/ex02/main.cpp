#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <new>

int main() {
  try {
    std::cout << "\n===== Animal Instantiation Test =====" << std::endl;
    // Should not compile //
    // Animal a;
    // const Animal *ptrAnimal = new Animal();

    std::cout << "===== Basic Creation =====" << std::endl;
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << "\n===== Sounds =====" << std::endl;
    dog->makeSound();
    cat->makeSound();

    std::cout << "\n===== Deep Copy Test =====" << std::endl;
    Dog basicDog;
    {
      Dog tempDog = basicDog;
      std::cout << "--- End of tempDog scope ---" << std::endl;
    }

    std::cout << "\n===== Array Test =====" << std::endl;
    const Animal *animals[4];
    for (int i = 0; i < 2; ++i)
      animals[i] = new Dog();
    for (int i = 2; i < 4; ++i)
      animals[i] = new Cat();

    std::cout << "\n===== Cleanup =====" << std::endl;
    for (int i = 0; i < 4; ++i)
      delete animals[i];

    delete dog;
    delete cat;

    std::cout << "\n===== End of Tests =====" << std::endl;

  } catch (const std::bad_alloc &e) {
    std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
