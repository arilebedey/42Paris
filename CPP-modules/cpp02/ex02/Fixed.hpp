#include <cmath>
#include <iostream>

class Fixed {
private:
  int _rawBits;
  static const int _fractionalBits = 8;

public:
  Fixed();
  Fixed(const int raw);
  Fixed(const float raw);
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  bool operator<(const Fixed &other) const;
  bool operator>(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;
  Fixed operator++();
  Fixed operator++(int);
  Fixed operator--();
  Fixed operator--(int);

  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  static Fixed &min(Fixed &a, Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static Fixed const &min(Fixed const &a, Fixed const &b);
  static Fixed const &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
