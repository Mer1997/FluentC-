#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto main(int argc, char *argv[]) -> int {
  
  vector<int> vec = {1, 2, 3, 4, 5};

  //remove_if 函数返回应当移除的第一个迭代器
  auto new_end = remove_if(vec.begin(), vec.end(), [](int val){return val == 3;});

  //remove_if 并未删除迭代器，而是移动和覆盖
  for( auto val: vec) {
    cout << val << " ";
  }
  cout << endl;

  //配合 erase 删除不需要的迭代器
  vec.erase(new_end, vec.end());

  for( auto val: vec) {
    cout << val << " ";
  }
  cout << endl;

  //find_if 返回第一个符合条件的迭代器，否则返回 end
  auto target = find_if(vec.begin(), vec.end(), [](int val) {return val == 4;});
  if(target != vec.end()) {
    cout << "target: " << *target << endl;
    cout << "index(begin with 0): " << (target - vec.begin()) << endl;
  }

  //copy_if

  //remove_copy_if
  
  return 0;
}
