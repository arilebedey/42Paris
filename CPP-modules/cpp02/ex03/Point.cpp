#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::~Point() {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(Point const &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(Point const &other) {
  (void)other;
  return *this;
}

Fixed Point::getX() const { return _x; }

Fixed Point::getY() const { return _y; }
