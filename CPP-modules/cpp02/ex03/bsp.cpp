#include "Point.hpp"

static Fixed area(const Point &p1, const Point &p2, const Point &p3) {
  Fixed result = ((p1.getX() * (p2.getY() - p3.getY())) +
                  (p2.getX() * (p3.getY() - p1.getY())) +
                  (p3.getX() * (p1.getY() - p2.getY()))) /
                 Fixed(2);
  if (result < Fixed(0))
    result = result * Fixed(-1);
  return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed a0, a1, a2, a3;

  a0 = area(a, b, c);
  a1 = area(a, b, point);
  a2 = area(b, c, point);
  a3 = area(c, a, point);

  if (a1 == Fixed(0) || a2 == Fixed(0) || a3 == Fixed(0))
    return (false);
  else if (a0 == (a1 + a2 + a3))
    return (true);
  else
    return (false);
}
