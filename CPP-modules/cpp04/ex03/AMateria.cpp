#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return _type; }

AMateria &AMateria::operator=(const AMateria &other) {
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

void AMateria::use(ICharacter &target) {
  std::cout << "* uses " << _type << " on " << target.getName() << " *"
            << std::endl;
}
