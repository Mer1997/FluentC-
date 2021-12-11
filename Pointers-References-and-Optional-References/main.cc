#include <iostream>
using namespace std;

class MyClass {
public:
  explicit MyClass(int &value)
      : value(value)
  {}
  virtual ~MyClass(void) {}

  void inc(void) { value++; }
private:
  // 普通的引用绑定之后无法更换
  int &value;
};

class MyClassWithRefWrapper {
public:
  explicit MyClassWithRefWrapper(int &_value)
  : value(_value)
  {}
  virtual ~MyClassWithRefWrapper(void) {}

  void inc(void) { value++; }

  // reference_wrapper 可以使用 std::ref 更换其所绑定的引用对象
  void rebind(int &new_value) {
    value = std::ref(new_value);
  }
private:
  std::reference_wrapper<int> value;
};

auto main(void) -> int
{

  auto value = int {};
  auto myclass = MyClass { value };
  myclass.inc();

  // value: 1
  cout << "value: " << value << endl;

  auto myClass1 = MyClassWithRefWrapper { value };
  myclass.inc();

  // value: 2
  cout << "value: " << value << endl;

  auto new_value = int{};

  // 将 myClass1 所拥有的引用重新绑定到 new_value 上
  myClass1.rebind(new_value);
  myClass1.inc();

  // value: 2
  // new_value: 1
  cout << "value: " << value << endl;
  cout << "new_value: " << new_value << endl;

  return 0;
}
