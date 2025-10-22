#include "Zombie.hpp"
#include <new>

Zombie *zombieHorde(int N, std::string name) {
  if (N <= 0)
    return 0;

  Zombie *horde = new (std::nothrow) Zombie[N];
  if (!horde)
    return 0;

  for (int i = 0; i < N; ++i)
    horde[i].setName(name);

  return horde;
}
