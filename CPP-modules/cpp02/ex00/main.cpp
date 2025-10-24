#include "Fixed.hpp"
#include <climits>

int main(void) {
  Fixed a;
  Fixed b(a);
  Fixed c;

  c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;

  std::cout << "\n--- Setting _rawBits in a to INT_MAX and using copy copy ---";
  std::cout
      << "\n--- constructor on a to populate c with new _rawBits value ---";
  std::cout << std::endl;
  std::cout << std::endl;

  a.setRawBits(INT_MAX);
  c = a;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  return 0;
}
