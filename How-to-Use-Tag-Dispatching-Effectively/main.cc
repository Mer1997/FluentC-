#include <iostream>
using namespace std;

// 标签的定义方式
class MyClass {
public:
  struct constructThisWay {};
  struct constructThatWay {};
  MyClass() = default;

  // 关键在于对相同名字相同参数类型但行为相对独立的两个函数，通过标签予以区分到
  // 两条路径，可以使函数更清晰
  // explicit 可以避免不期望的隐式转换
  explicit MyClass(constructThisWay);
  explicit MyClass(constructThatWay);
};

MyClass::MyClass(constructThisWay)
{
  cout << "construct by this way" << endl;
}

MyClass::MyClass(constructThatWay)
{
  cout << "construct by that way" << endl;
}

class MyClass_1 {
public:
  //这种定义方式可以在使用时更加方便，也更符合 Tag 的语义
  static struct ConstructThisWay {} constructThisWay;
  static struct ConstructThatWay {} constructThatWay;
  MyClass_1() = default;

  explicit MyClass_1(ConstructThisWay);
  explicit MyClass_1(ConstructThatWay);
};

MyClass_1::MyClass_1(ConstructThisWay)
{
  cout << "construct by this way" << endl;
}

MyClass_1::MyClass_1(ConstructThatWay)
{
  cout << "construct by that way" << endl;
}

auto main(void) -> int {
  // 标签的使用方式
  MyClass my_1(MyClass::constructThisWay{});
  MyClass my_2(MyClass::constructThatWay{});
  
  // 标签的使用方式2
  MyClass_1 my_3(MyClass_1::constructThisWay);
  MyClass_1 my_4(MyClass_1::constructThatWay);
  
  return 0;
}
