#include "Zombie.hpp"
#include <iostream>

int main(void) {
  int horde_count = 5;
  Zombie *horde = zombieHorde(horde_count, "Hord-Zomb");
  if (!horde) {
    std::cout << "Horde alloc failed!" << std::endl;
    return 1;
  }

  for (int i = 0; i < horde_count; ++i)
    horde[i].announce();

  delete[] horde;

  return 0;
}
