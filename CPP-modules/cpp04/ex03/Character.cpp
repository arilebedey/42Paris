#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character() : _name("Default"), _floor(0), _floorCount(0) {
  for (int i = 0; i < 4; ++i)
    _inventory[i] = 0;
}

Character::Character(std::string name)
    : _name(name), _floor(0), _floorCount(0) {
  for (int i = 0; i < 4; ++i)
    _inventory[i] = 0;
}

Character::Character(const Character &other)
    : _name(other._name), _floor(0), _floorCount(0) {
  for (int i = 0; i < 4; ++i)
    _inventory[i] = 0;
  _copyInventory(other);
}

Character::~Character() {
  _clearInventory();
  for (int i = 0; i < _floorCount; ++i)
    delete _floor[i];
  delete[] _floor;
}

Character &Character::operator=(const Character &other) {
  if (this != &other) {
    _name = other._name;
    _clearInventory();
    _copyInventory(other);
  }
  return *this;
}

void Character::_clearInventory() {
  for (int i = 0; i < 4; ++i) {
    if (_inventory[i]) {
      delete _inventory[i];
      _inventory[i] = 0;
    }
  }
}

void Character::_copyInventory(const Character &other) {
  for (int i = 0; i < 4; ++i) {
    if (other._inventory[i])
      _inventory[i] = other._inventory[i]->clone();
    else
      _inventory[i] = 0;
  }
}

void Character::_addToFloor(AMateria *m) {
  if (!m)
    return;
  AMateria **newFloor = new AMateria *[_floorCount + 1];
  for (int i = 0; i < _floorCount; ++i)
    newFloor[i] = _floor[i];
  newFloor[_floorCount] = m;
  delete[] _floor;
  _floor = newFloor;
  _floorCount++;
}

const std::string &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
  if (!m) {
    std::cout << "Cannot equip null materia" << std::endl;
    return;
  }
  for (int i = 0; i < 4; ++i) {
    if (_inventory[i] == 0) {
      _inventory[i] = m;
      std::cout << _name << " equipped " << m->getType() << " in slot " << i
                << std::endl;
      return;
    }
  }
  std::cout << "Inventory full for " << _name << std::endl;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4 || !_inventory[idx]) {
    std::cout << "Invalid unequip index for " << _name << std::endl;
    return;
  }
  std::cout << _name << " unequipped " << _inventory[idx]->getType()
            << " (moved to floor, will be cleaned on destruction)" << std::endl;
  _addToFloor(_inventory[idx]);
  _inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < 4 && _inventory[idx])
    _inventory[idx]->use(target);
  else
    std::cout << "Invalid index or empty slot in use" << std::endl;
}
