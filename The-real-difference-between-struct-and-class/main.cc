#include <iostream>
using namespace std;

namespace geometry
{
  const static double Pi = 3.1415926535897932384626;
  class Circle
  {
    public:
      explicit Circle(double radius) : m_radius(radius) {}

      double getRadius() const {return m_radius;}

    private:
      double m_radius;
  };

  double getPerimeter(Circle const& circle) {return 2 * Pi * circle.getRadius();}
  double getArea(Circle const& circle) {return Pi * circle.getRadius() * circle.getRadius();}
} // end of namespace geometry

auto main(void) -> int {

  geometry::Circle circle(1.0);

  cout << circle.getRadius() << endl;

  //这里由于 ADL(Argument Dependent Lookup) 机制会将调用参数命名空间中的函数
  //带到函数搜索范围, 因而不必显式声明命名空间
  //也就是说，由于 getPerimeter 的参数是 Circle, 因此 Circle 所在的命名空间内
  //的所有函数（当然包括 getPerimeter）都不必再声明 geometry::
  cout << getPerimeter(circle) << endl;
  
  return 0;
}
