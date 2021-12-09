#include <iostream>
using namespace std;

template<typename T>
class Wrapper
{
public:
    Wrapper(T const& value) : value_(value) {}
    
    // 对于 int& 的情况:
    // const (int&) 含义类似与 int* const, 即引用的对象不能变更，但由于引用定义后本身
    // 就无法重绑定，因此 const (int&) 效果等同于 int&
    // int& & 则被编译器解释为 int&
    // 因此，如果使用 int& 初始化 T ，则 get 函数返回的是 value 的引用！可以被随意修改
    T const& get() const { return value_; }
    
private:
    T value_;
};

template<typename T>
class SafeWrapper
{
public:
    SafeWrapper(T const& value) : value_(value) {}
    
    // c++14
    std::remove_reference_t<T> const& get() const { return value_; }
    
private:
    T value_;
};

auto main() -> int
{
    int a = 42;

    using IntWrapper = Wrapper<int>;
    IntWrapper intWrapper(a);
    
    // Compile Error
    // intWrapper.get() = 43;
    std::cout << "a is now " << a << '\n';

    using IntRefWrapper = Wrapper<int&>;
    IntRefWrapper intRefWrapper(a);
    
    intRefWrapper.get() = 43;

    // 这里实际改变了 a 的值
    std::cout << "a is now " << a << '\n';

    using IntRefSafeWrapper = SafeWrapper<int&>;
    IntRefSafeWrapper intRefSafeWrapper(a);
    
    // Compile Error
    // intRefSafeWrapper.get() = 44;

    std::cout << "a is now " << a << '\n';

}
