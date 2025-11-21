#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; ++i)
    materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
  for (int i = 0; i < 4; ++i) {
    if (other.materias[i])
      materias[i] = other.materias[i]->clone();
    else
      materias[i] = 0;
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this != &other) {
    for (int i = 0; i < 4; ++i) {
      delete materias[i];
      if (other.materias[i])
        materias[i] = other.materias[i]->clone();
      else
        materias[i] = 0;
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; ++i) {
    delete materias[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  if (!m) {
    std::cout << "Cannot learn null materia" << std::endl;
    return;
  }
  for (int i = 0; i < 4; ++i) {
    if (!materias[i]) {
      materias[i] = m;
      std::cout << "MateriaSource learned " << m->getType() << std::endl;
      return;
    }
  }
  std::cout << "MateriaSource is full, cannot learn more materias" << std::endl;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i = 0; i < 4; ++i) {
    if (materias[i] && materias[i]->getType() == type) {
      return materias[i]->clone();
    }
  }
  std::cout << "Materia of type " << type << " not found" << std::endl;
  return 0;
}
