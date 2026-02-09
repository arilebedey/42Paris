#include "Fixed.hpp"

class Point {
private:
  Fixed const _x;
  Fixed const _y;

public:
  Point();
  ~Point();
  Point(float const x, float const y);
  Point(Point const &src);
  Point &operator=(Point const &other);

  Fixed getX() const;
  Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const p);
