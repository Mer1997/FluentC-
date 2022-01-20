#include "Frige.h"
using namespace std;

auto main(void) -> int {

  //Firge 的实现由 FrigeImpl 完成，Frige 类本身只负责控制 FrigeImpl 类的声明周期和任务交付，因此实现了一层隔离: 当 FrigeImpl 内的类型 Engine 发生更改时，那些依赖 Frige 的类不需要重新编译
  Frige frige;
  frige.cooldown("273.15k");
  
  return 0;
}
