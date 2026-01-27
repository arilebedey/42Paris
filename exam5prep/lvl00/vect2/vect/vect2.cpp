#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::vect2(int x, int y) : x(x), y(y) {}

vect2::vect2(const vect2 &v) {
  x = v.x;
  y = v.y;
}

vect2 &vect2::operator=(const vect2 &v) {
  if (this != &v) {
    this->x = v.x;
    this->y = v.y;
  }
  return *this;
}

vect2::~vect2() {}

int &vect2::operator[](int i) {
  if (i == 0)
    return x;
  return y;
}

const int &vect2::operator[](int i) const {
  if (i == 0)
    return x;
  return y;
}

std::ostream &operator<<(std::ostream &os, const vect2 &v) {
  os << "{" << v[0] << ", " << v[1] << "}";
  return os;
}

vect2 &vect2::operator++() {
  x += 1;
  y += 1;
  return (*this);
}

vect2 vect2::operator++(int) {
  vect2 v = *this;
  ++(*this);
  return v;
}

vect2 &vect2::operator--() {
  x -= 1;
  y -= 1;
  return (*this);
}

vect2 vect2::operator--(int) {
  vect2 v = *this;
  --(*this);
  return v;
}

vect2 &vect2::operator+=(const vect2 n) {
  x += n.x;
  y += n.y;
  return (*this);
}

vect2 &vect2::operator-=(const vect2 n) {
  x -= n.x;
  y -= n.y;
  return (*this);
}

vect2 vect2::operator*(const int n) const {
  vect2 nv(x * n, y * n);
  return nv;
}

vect2 vect2::operator+(const vect2 v) const {
  vect2 n(*this);
  n += v;
  return n;
}

vect2 operator*(const int n, const vect2 v) { return v * n; }

vect2 &vect2::operator*=(const int n) {
  vect2 nv(x * n, y * n);
  *this = nv;
  return *this;
}
