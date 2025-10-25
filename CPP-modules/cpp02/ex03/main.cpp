#include "Point.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define CHECKMARK "\u2714"
#define CROSS "\u2716"

void test(Point const &a, Point const &b, Point const &c, Point const &p) {
  std::cout << CYAN << "Test du point (" << p.getX() << ", " << p.getY()
            << ") : ";
  if (bsp(a, b, c, p))
    std::cout << GREEN << CHECKMARK << " À l'intérieur du triangle" << RESET
              << std::endl;
  else
    std::cout << RED << CROSS << " À l'extérieur du triangle" << RESET
              << std::endl;
}

int main(void) {
  std::cout << BOLD << "=== Test de la fonction bsp ===" << RESET << std::endl;

  Point a(0, 0);
  Point b(10, 0);
  Point c(5, 10);

  std::cout << YELLOW << "Triangle formé par les points : " << RESET
            << std::endl;
  std::cout << "- A(0, 0)" << std::endl;
  std::cout << "- B(10, 0)" << std::endl;
  std::cout << "- C(5, 10)" << std::endl << std::endl;

  // Tests
  test(a, b, c, Point(5, 5));       // Intérieur ✔️
  test(a, b, c, Point(4.9f, 4.9f)); // Intérieur (floats)
  test(a, b, c, Point(5, 10));      // Sommet ❌
  test(a, b, c, Point(10, 10));     // Extérieur ❌

  return 0;
}
