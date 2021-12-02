#include <iostream>
#include <string>
#include <string_view>
using namespace std;

auto print(string_view msg) -> void {
  cout << msg << endl;
}

// 1. 为 cout 下毒，对于之后的代码包含 cout 将不能通过编译, 之前的代码不受影响
#pragma GCC poison cout

// #define POISON_SWITCH
// 2. 通过宏控制 poison 的开关
#ifdef POISON_SWITCH
#pragma GCC poison print
#endif

// 3. 有趣的用法：
// a. 用于阻止接口使用者的某些调用
// b. 防止使用某些已弃用的接口

auto main(void) -> int {

  // 1. error: attempt to use a poisoned identifier
  // cout << "Hello World" << endl;

  // 1. ok
  // 2. 如果开启 POISON_SWITCH 则编译无法通过
  print("Hello World");
  
  return 0;
}
