#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(Point const &src) : _x(src._x), _y(src._y) {}

Point &Point::operator=(Point const &other) {
  if (this != &other)
    return *this;
  return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return _x; }

Fixed Point::getY() const { return _y; }
