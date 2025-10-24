#include "Zombie.hpp"
#include <iostream>

int main(void) {
  std::cout << "Creating zombie on stack:\n";
  Zombie stackZombie("Stack-Zomb");
  stackZombie.announce();

  std::cout << "\n";
  std::cout << "Creating zombie on heap:\n";
  Zombie *heapZombie = newZombie("Heap-Zomb");
  if (heapZombie) {
    heapZombie->announce();
    std::cout << "\n";
    std::cout << "Destroying heap zombie manually:\n";
    delete heapZombie;
  } else
    std::cout << "Heap zombie allocation failed.\n";

  std::cout << "\n";
  std::cout << "Creating temporary zombie via randomChump:\n";
  randomChump("Temp-Zomb");

  std::cout << "\n";
  return (0);
}
