#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*检查类型 T 是否可以做 ++ 运算*/
namespace v_1 {
  template <typename , typename = void>
    struct is_incrementable : std::false_type {};
  template <typename T>
    struct is_incrementable<T, std::void_t<decltype(++std::declval<T&>())>> : std::true_type {};
}

/*More expressive*/
namespace v_2 {
  template <typename...Ts>
    using try_to_instantiate = void_t<Ts...>;
  template <typename T, typename Attempt = void>
    struct is_incrementable : false_type {};
  template <typename T>
    struct is_incrementable<T, try_to_instantiate<decltype(++std::declval<T&>())>> : std::true_type {};
}

/*更具推广性的模板，检查任意表达式是否可以完成运算*/
namespace v_3 {
  template <typename...Ts>
    using try_to_instantiate = void_t<Ts...>;

  using disregard_this = void;

  template <template<typename...> class Expression, typename Attempt, typename... Ts>
    struct is_detected_impl : false_type {};
  template <template<typename...> class Expression, typename... Ts>
    struct is_detected_impl<Expression, try_to_instantiate<Expression<Ts...>>, Ts...> : std::true_type {};
  template <template<typename...> class Expression, typename... Ts>
    constexpr bool is_detected = is_detected_impl<Expression, disregard_this, Ts...>::value;

  //检查类型 T 是否可以做 ++ 运算
  template <typename T>
    using increment_expression = decltype(++std::declval<T&>());
  template <typename T>
    constexpr bool is_incrementable = is_detected<increment_expression, T>;

  //检查类型 T 是否可以初始化类型 U
  template <typename T, typename U>
    using assign_expression = decltype(std::declval<T&>() = std::declval<U&>());
  template <typename T, typename U>
    constexpr bool is_assignable = is_detected<assign_expression, T, U>;
}

auto main(void) -> int {

  static_assert(v_1::is_incrementable<int>::value == true);
  static_assert(v_2::is_incrementable<int>::value == true);
  static_assert(v_3::is_incrementable<int> == true);

  static_assert(v_3::is_assignable<int, double> == true);
  static_assert(v_3::is_assignable<int, std::string> == false);
  
  std::cout << "It works!" << std::endl;

  return 0;
}
