#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << Fixed::max(a, b) << std::endl;

  std::cout << "---other tests---" << std::endl;
  std::cout << a + b << std::endl;
  Fixed c;
  c = b - a;
  Fixed d(a);
  std::cout << "c : " << c << "et d : " << d << std::endl;
  std::cout << "max between c and d : " << Fixed::max(c, d) << std::endl;

  Fixed test;
  test = d / 3;
  std::cout << "d divided by 3 : " << std::endl;
  std::cout << test << std::endl;
  return 0;
}
