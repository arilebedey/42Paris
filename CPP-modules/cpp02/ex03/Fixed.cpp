#include "Fixed.hpp"

Fixed::Fixed() { this->_rawBits = 0; }

Fixed::Fixed(const int raw) { this->_rawBits = raw * (1 << _fractionalBits); }

Fixed::Fixed(const float raw) {
  this->_rawBits = static_cast<int>(roundf(raw * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &other) { this->_rawBits = other.getRawBits(); }

Fixed &Fixed::operator=(const Fixed &other) {
  if (&other != this)
    this->_rawBits = other.getRawBits();
  return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return this->_rawBits; }

void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(this->_rawBits /
                            static_cast<float>(1 << _fractionalBits));
}

int Fixed::toInt(void) const { return _rawBits / (1 << _fractionalBits); }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return (out);
}

bool Fixed::operator<(const Fixed &other) const {
  return this->_rawBits < other._rawBits;
}

bool Fixed::operator>(const Fixed &other) const {
  return this->_rawBits > other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const {
  return this->_rawBits <= other._rawBits;
}

bool Fixed::operator>=(const Fixed &other) const {
  return this->_rawBits >= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const {
  return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const {
  return this->_rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const {
  float result = this->toFloat() + other.toFloat();
  return (Fixed(result));
}

Fixed Fixed::operator-(const Fixed &other) const {
  float result = this->toFloat() - other.toFloat();
  return (Fixed(result));
}

Fixed Fixed::operator*(const Fixed &other) const {
  float result = this->toFloat() * other.toFloat();
  return (Fixed(result));
}

Fixed Fixed::operator/(const Fixed &other) const {
  if (other.toFloat() == 0) {
    std::cerr << "Division par 0 impossible, remplacée par 1" << std::endl;
    return *this;
  }
  float result = this->toFloat() / other.toFloat();
  return (Fixed(result));
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  _rawBits++;
  return temp;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  _rawBits--;
  return temp;
}

Fixed Fixed::operator++() {
  _rawBits++;
  return *this;
}

Fixed Fixed::operator--() {
  _rawBits--;
  return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a > b)
    return (b);
  return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a > b)
    return (a);
  return (b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
  if (a > b)
    return b;
  return a;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
  if (a > b)
    return a;
  return b;
}
