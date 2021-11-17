#include <iostream>
#include <functional>
#include <random>
#include <ctime>
using namespace std;

// 某个可能被替换的函数实现
auto newIdFromRandomGen() -> int
{
  static std::default_random_engine e;
  static std::uniform_int_distribution<unsigned> dis(1, 100);
  auto dice = std::bind(dis, e);
  return dice();
}

// 声明一个中间函数用于解构实现, 例如：
// int newId() {
//   return newIdFromDatabase();
// }

// 生成函数别名用于代替中间函数，实质上是一个函数指针（auto 永远的神）
const auto newId = newIdFromRandomGen;

// 为模板函数设置别名
template<typename T>
void print(const T &value) 
{
  cout << "The value is :" << value << endl;
  return;
}

template<typename T>
const auto NewPrint = print<T>;

auto main(void)->int {
  auto id = newId();
  cout << "New Id: " << id << endl;

  // 模板函数的别名相比普通函数降低了可读性
  NewPrint<decltype(id)>(id);

  return 0;
}
