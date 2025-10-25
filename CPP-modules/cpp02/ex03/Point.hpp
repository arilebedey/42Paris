#include "Fixed.hpp"

class Point {
public:
  Point();
  Point(float const x, float const y);
  Point(Point const &src);
  ~Point();
  Point &operator=(Point const &other);
  Fixed getX() const;
  Fixed getY() const;

private:
  Fixed const _x;
  Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
