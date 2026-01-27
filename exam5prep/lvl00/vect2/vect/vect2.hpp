#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {
private:
  int x;
  int y;

public:
  vect2();
  vect2(int x, int y);
  vect2(const vect2 &v);
  vect2 &operator=(const vect2 &v);
  ~vect2();

  int &operator[](int i);
  const int &operator[](int i) const;

  vect2 &operator++();
  vect2 operator++(int);

  vect2 &operator--();
  vect2 operator--(int);

  vect2 &operator+=(const vect2 n);
  vect2 &operator-=(const vect2 n);

  vect2 operator*(const int n) const;
  vect2 operator+(const vect2 n) const;

  vect2 &operator*=(const int n);
};

std::ostream &operator<<(std::ostream &os, const vect2 &v);
vect2 operator*(const int n, const vect2 v);

#endif
