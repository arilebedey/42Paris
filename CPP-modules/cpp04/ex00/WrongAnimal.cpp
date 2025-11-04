#ifndef WRONANIMAL_HPP
#define WRONANIMAL_HPP

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
  std::cout << "WrongAnimal constructor with type param called" << std::endl;
  std::cout << "Type: " << _type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  std::cout << "Type: " << _type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  if (this != &other) {
    _type = other._type;
  }
  std::cout << "WrongAnimal assignment operator called" << std::endl;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal makes sound" << std::endl;
}

std::string WrongAnimal::getType() const { return _type; }

#endif
