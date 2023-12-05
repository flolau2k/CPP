#include "Point.hpp"

Fixed cross_check(const Point a, const Point b, const Point p) {
  const Point i =
      Point((a.getX() - b.getX()).toFloat(), (a.getY() - b.getY()).toFloat());
  const Point j =
      Point((a.getX() - p.getX()).toFloat(), (a.getY() - p.getY()).toFloat());
  const Fixed res = i.getX() * j.getY() - i.getY() * j.getX();
  return res;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  const Fixed abp(cross_check(a, b, point));
  const Fixed bcp(cross_check(b, c, point));
  const Fixed cap(cross_check(c, a, point));
  std::cout << "abp " << abp.toFloat() << std::endl;
  std::cout << "acp " << bcp.toFloat() << std::endl;
  std::cout << "bcp " << cap.toFloat() << std::endl;
  if ((abp > 0 && bcp > 0 && cap > 0) || (abp < 0 && bcp < 0 && cap < 0))
    return true;
  return false;
}

int main(void) {
  const Point a;
  const Point b(-1, 0);
  const Point c(0, 1);
  const Point p(-0.3, -0.3);

  bool inT = bsp(a, b, c, p);

  std::cout << "p is ";
  if (!inT)
    std::cout << "not ";
  std::cout << "in the triangle" << std::endl;

  return 0;
}
