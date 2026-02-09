#include "Point.hpp"

static Fixed area(const Point &p1, const Point &p2, const Point &p3) {
  Fixed dx1 = p2.getX() - p1.getX();
  Fixed dy1 = p2.getY() - p1.getY();
  Fixed dx2 = p3.getX() - p1.getX();
  Fixed dy2 = p3.getY() - p1.getY();

  Fixed cross = (dx1 * dy2) - (dx2 * dy1);
  if (cross < Fixed(0))
    cross = cross * Fixed(-1);
  return cross / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
  Fixed seeked_area = area(a, b, c);
  Fixed ar1 = area(a, c, p);
  Fixed ar2 = area(b, a, p);
  Fixed ar3 = area(b, c, p);

  if (ar1 == Fixed(0) || ar2 == Fixed(0) || ar3 == Fixed(0))
    return false;

  if (seeked_area != (ar1 + ar2 + ar3))
    return false;

  return true;
}
