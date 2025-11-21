#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) { (void)other; }

AMateria &AMateria::operator=(const AMateria &other) {
  (void)other;
  return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) {
  std::cout << "* uses " << _type << " on " << target.getName() << " *"
            << std::endl;
}
