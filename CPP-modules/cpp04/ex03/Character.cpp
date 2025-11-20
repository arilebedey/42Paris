#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character()
    : _name("Default"), _idx(0), _registry(0), _registrySize(0) {
  for (int i = 0; i < 4; ++i) {
    _inventory[i].ptr = 0;
    _inventory[i].owned = false;
  }
}

Character::Character(std::string name)
    : _name(name), _idx(0), _registry(0), _registrySize(0) {
  for (int i = 0; i < 4; ++i) {
    _inventory[i].ptr = 0;
    _inventory[i].owned = false;
  }
}

Character::Character(const Character &other)
    : _name(other._name), _idx(other._idx), _registry(0), _registrySize(0) {
  for (int i = 0; i < 4; ++i) {
    if (other._inventory[i].ptr && other._inventory[i].owned) {
      _inventory[i].ptr = other._inventory[i].ptr->clone();
      _inventory[i].owned = true;
    } else if (other._inventory[i].ptr) {
      _inventory[i].ptr = other._inventory[i].ptr;
      _inventory[i].owned = false;
    } else {
      _inventory[i].ptr = 0;
      _inventory[i].owned = false;
    }
  }
}

Character::~Character() {
  for (int i = 0; i < 4; ++i)
    if (_inventory[i].owned && _inventory[i].ptr)
      delete _inventory[i].ptr;
  for (int i = 0; i < _registrySize; ++i)
    if (_registry[i].owned && _registry[i].ptr)
      delete _registry[i].ptr;
  delete[] _registry;
}

Character &Character::operator=(const Character &other) {
  if (this != &other) {
    _name = other._name;
    _idx = other._idx;
    for (int i = 0; i < 4; ++i) {
      if (_inventory[i].owned && _inventory[i].ptr)
        delete _inventory[i].ptr;
      if (other._inventory[i].ptr && other._inventory[i].owned) {
        _inventory[i].ptr = other._inventory[i].ptr->clone();
        _inventory[i].owned = true;
      } else if (other._inventory[i].ptr) {
        _inventory[i].ptr = other._inventory[i].ptr;
        _inventory[i].owned = false;
      } else {
        _inventory[i].ptr = 0;
        _inventory[i].owned = false;
      }
    }
  }
  return *this;
}

const std::string &Character::getName() const { return _name; }

void Character::equip(AMateria *m) { equip(m, true); }

void Character::equip(AMateria *m, bool takeOwnership) {
  if (!m) {
    std::cout << "Cannot equip null materia" << std::endl;
    return;
  }
  for (int i = 0; i < 4; ++i) {
    if (!_inventory[i].ptr) {
      _inventory[i].ptr = m;
      _inventory[i].owned = takeOwnership;
      std::cout << _name << " equipped " << m->getType() << " in slot " << i;
      if (!takeOwnership)
        std::cout << " (external, not owned)";
      std::cout << std::endl;
      return;
    }
  }
  std::cout << "Inventory full for " << _name << std::endl;
}

void Character::_expandRegistry() {
  MateriaSlot *newReg = new MateriaSlot[_registrySize + 1];
  for (int i = 0; i < _registrySize; ++i)
    newReg[i] = _registry[i];
  delete[] _registry;
  _registry = newReg;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4 || !_inventory[idx].ptr) {
    std::cout << "Invalid unequip index for " << _name << std::endl;
    return;
  }
  _expandRegistry();
  _registry[_registrySize].ptr = _inventory[idx].ptr;
  _registry[_registrySize].owned = _inventory[idx].owned;
  _registrySize++;
  std::cout << _name << " unequipped " << _inventory[idx].ptr->getType()
            << " (stored safely in registry)" << std::endl;
  _inventory[idx].ptr = 0;
  _inventory[idx].owned = false;
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < 4 && _inventory[idx].ptr)
    _inventory[idx].ptr->use(target);
  else
    std::cout << "Invalid index or empty slot in use" << std::endl;
}
