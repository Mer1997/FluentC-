#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void print_vec(const vector<int> &vec) {
  for_each(begin(vec), end(vec), [](const int &el) {
    std::cout << el << " "; 
  });
  std::cout << std::endl;
}

auto main(int argc, char *argv[]) -> int {
  std::vector<int> v1;
  std::vector<int> v2 = {1, 3, 4, 2, -1, -29};

  print_vec(v2);
  std::copy(begin(v2), end(v2), back_inserter(v1));
  print_vec(v1);

  std::vector<int> v3{begin(v2), end(v2)};
  print_vec(v3);

  std::vector<int> v4 = {99};
  v4.insert(end(v4), begin(v2), end(v2));
  print_vec(v4);

  std::vector<int> v5 = {99};
  v5.assign(begin(v2), end(v2));
  print_vec(v5);
  print_vec(v2);

  //recommend to use std::back_inserter when copy_if
  std::vector<int> v6;
  std::copy_if(begin(v2), end(v2), back_inserter(v6), [](const int &el) {return el > 0;});
  print_vec(v6);

  return 0;
}
