#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <experimental/type_traits>
using namespace std;

namespace tools {

  template<typename T>
    using std_to_string_expression = decltype(std::to_string(std::declval<T>()));
  template<typename T>
    constexpr bool has_std_to_string = experimental::is_detected<std_to_string_expression, T>::value;

  template<typename T>
    using to_string_expression = decltype(to_string(std::declval<T>()));
  template<typename T>
    constexpr bool has_to_string = experimental::is_detected<to_string_expression, T>::value;

  template<typename T>
    using ostringstream_expression = decltype(std::declval<std::ostringstream&>() << std::declval<T>());
  template<typename T>
    constexpr bool has_ostringstream = experimental::is_detected<ostringstream_expression, T>::value;

  template<typename T, typename std::enable_if<has_std_to_string<T>, int>::type = 0>
    std::string toString(T const& t) {
      return std::to_string(t);
    }
  template<typename T, typename std::enable_if<!has_std_to_string<T> && has_to_string<T>, int>::type = 0>
    std::string toString(T const& t) {
      return to_string(t);
    }
  template<typename T, typename std::enable_if<!has_std_to_string<T> && !has_to_string<T> && has_ostringstream<T>, int>::type = 0>
    std::string toString(T const& t) {
      std::ostringstream oss;
      oss << t;
      return oss.str();
    }
}

namespace NA
{
  class A {};
  std::string to_string(A const&) {
    return "to_string(A)";
  }
}

namespace NB
{
  class B {};
  std::ostream& operator<<(std::ostream& os, B const&) { 
    os << "oss(B)"; return os; 
  }
}

auto main(void) -> int {

  static_assert(tools::has_std_to_string<int>);

  std::cout << tools::toString(42) << '\n';
  std::cout << tools::toString(NA::A()) << '\n';
  std::cout << tools::toString(NB::B()) << '\n';
  
  return 0;
}
