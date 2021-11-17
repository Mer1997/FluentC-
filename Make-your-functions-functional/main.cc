#include <iostream>
#include <optional>
#include <string>
#include <algorithm>
using namespace std;

//理想的函数形式
//Output func(const Input &in) {...}
//Output out = func(in);

//使用 optional 代替
// bool ret = func(in, out);
optional<string> func(const int &id) {
  if(id < 0) { return nullopt; }
  return to_string(id);
}

//使用 tuple 返回多个结果, 代替
//out1 = funcc(in1, in2, out1, out2, out3);
optional<tuple<string, string, int, double>> funcc(const string &name) {
  if(name != "Mer") {
    return nullopt;
  }else {
    return {{
      "202009270001",
      "Mer",
      24,
      99.7
    }};
  }
}

auto main(void) -> int {

  auto ret1 = func(20);
  if(ret1) 
    cout << *ret1 << endl;
  else 
    cout << "nullopt" << endl;

  auto ret2 = func(-3);
  if(ret2.has_value())  
    cout << *ret2 << endl;
  else 
    cout << "nullopt" << endl;

  auto stu1 = funcc("Mer");
  if(stu1) {
    auto [id, name, age, grade] = *stu1;
    cout << id << ", " << name << ", " << age << ", " << grade << endl;
  }else {
    cout << "nullopt" << endl;
  }
  
  return 0;
}
