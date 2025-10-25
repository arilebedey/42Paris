#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  this->_rawBits = 0;
}

Fixed::Fixed(const int raw) {
  std::cout << "Int constructor called" << std::endl;
  this->_rawBits = raw * (1 << _fractionalBits);
}

Fixed::Fixed(const float raw) {
  std::cout << "Float constructor called" << std::endl;
  this->_rawBits = static_cast<int>(roundf(raw * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  this->_rawBits = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (&other != this)
    this->_rawBits = other.getRawBits();
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const { return this->_rawBits; }

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(this->_rawBits /
                            static_cast<float>(1 << _fractionalBits));
}

int Fixed::toInt(void) const { return _rawBits / (1 << _fractionalBits); }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return (out);
}
