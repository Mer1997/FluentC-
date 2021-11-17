#include <iostream>
#include <optional>
using namespace std;

optional<int> f(int a) {
  return a+1;
}
optional<int> g2(int b, int c) {
  return b+c;
}
optional<int> h(int d) {
  return d+1;
}
optional<int> f4(int e) {
  return e+1;
}

template<typename T, typename TtoOptionalU>
auto operator>>=(optional<T> const& t, TtoOptionalU f) -> decltype(f(*t)) {
  if (t) {
    return f(*t);
  } else {
    return nullopt;
  }
}
auto main(void) -> int {
  // b is the result of f(3) if it succeeds
  optional<int> result = f(3) >>= [=](int b) { 
    // c is the result of f(4) if it succeeds
    return f(4) >>= [=](int c) {
      return g2(b, c) >>= [=](int d) { 
        return h(d) >>= [=](int e) { 
          return h(e);
        };};};};

  if(result)
    cout << *result << endl;

  return 0;
}
