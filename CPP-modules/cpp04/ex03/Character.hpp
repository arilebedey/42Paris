#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
private:
  std::string _name;
  AMateria *_inventory[4];
  AMateria **_floor;
  int _floorCount;

  void _clearInventory();
  void _copyInventory(const Character &other);
  void _addToFloor(AMateria *m);

public:
  Character();
  Character(std::string name);
  Character(const Character &other);
  ~Character();
  Character &operator=(const Character &other);

  const std::string &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif
