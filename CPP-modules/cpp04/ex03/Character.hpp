#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

struct MateriaSlot {
  AMateria *ptr;
  bool owned;
};

class Character : public ICharacter {
private:
  std::string _name;
  MateriaSlot _inventory[4];
  int _idx;

  MateriaSlot *_registry;
  int _registrySize;

  void _expandRegistry();

public:
  Character();
  Character(std::string name);
  Character(const Character &other);
  ~Character();
  Character &operator=(const Character &other);

  const std::string &getName() const;
  void equip(AMateria *m);
  void equip(AMateria *m, bool takeOwnership);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif
