#include <iostream>
using namespace std;

// lvalue 表示资源(resource)无法被重用的对象
// 例如 int y = f(x) 这里 x 和 y 就属于左值
// rvalue 表示资源(resource)可以被重用的对象
// 例如 g(MyClass()) 其中 MyClass() 生成的对象就是右值

// 对于函数 void f (MyClass&& x) {...}
// 这里所接收的右值引用表示 x 所绑定的对象在外部已被放弃，可以随意使用（例如 unique_ptr）
// 对于该函数的一个可能的调用： f(MyClass());

// 然而我们不能将一个左值引用传递给 f
// 例如： MyClass x; f(x); 是错误的
// 除非使用 std::move 将其转为 rvalue
// 例如： MyClass x; f(std::move(x));
// 意义在于此时外部已经不关心这个左值对象，而将其作为一个一次性对象处理, 因此我们需要确保该对象在外部已经不再使用

// 移动构造函数可以接受 rvalue
// MyClass
// {
// public:
//   MyClass (MyClass&& other) noexcept;
// };

// 在模板中 && 不一定代表右值引用
// template<typename T>
// void f(T&& x)
// {
// ...
// }
// 这里对于 f，x 的类型取决于传入的参数类型，也就是说
// 1. x is an lvalue reference if f received an lvalue, and
// 2. x is an rvalue reference if f received an rvalue.
// 称之为转发引用或通用引用(必须是 T&&，而不是 const T&& 或 vector<T>&&)

// 对于以下情况
// template<typename T>
// void g(T&& x)
// {
// ...
// }
// template<typename T>
// void f(T&& x)
// {
//   g(x);
// }
// 传递给 f 的右值引用会被当作左值传递给 g, 如果要保留引用类型，使用
// g(std::forward<T>(x));
// 注意这里如果是右值引用，forward 的行为等同于 move，因此需要保证 f 中后续代码不关心该对象


auto main(void) -> int
{
  static_assert(false);
  return 0;
}
