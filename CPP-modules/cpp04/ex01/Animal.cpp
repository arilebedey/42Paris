#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Unspecified animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &_type) : type(_type) {
  std::cout << "Animal constructor called with type: " << _type << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
  std::cout << "Animal copy constructor called with type: " << type
            << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
  if (this != &other) {
    type = other.type;
  }
  std::cout << "Animal assignment operator called" << std::endl;
  return *this;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }

std::string Animal::getType() const { return type; }
