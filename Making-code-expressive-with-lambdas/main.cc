#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Product {
  public:
  explicit Product (int number): number(number) {}
  int number;
};

//使用函数包装 lambda 表达式，增加抽象级别，增加代码可读性
auto resists(void) {
  return [](const Product& product){
    return product.number != 9 ? true : false;
  };
}

auto main(void) -> int {

  Product product_1(8);
  Product product_2(9);
  Product product_3(10);

  vector<Product> products;
  products.push_back(product_1);
  products.push_back(product_2);
  products.push_back(product_3);

  vector<Product> good_products;
  copy_if(products.begin() ,products.end(), back_inserter(good_products), resists());

  for(auto product: good_products) {
    cout << product.number << " ";
  }
  std::cout << std::endl;
  
  return 0;
}
