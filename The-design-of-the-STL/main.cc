#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class FlowCollection {

public:
  using Flow = int;
  using const_iterator = std::vector<Flow>::const_iterator;
  const_iterator begin() const {
    return m_flows.begin();
  }
  const_iterator end() {
    return m_flows.end();
  }
  void push_back(const Flow &flow) { m_flows.push_back(flow); }

private:
  std::vector<Flow> m_flows;
};

auto main(void) -> int {
  FlowCollection fc;
  fc.push_back(1);
  fc.push_back(2);
  for_each(begin(fc), end(fc),
           [](const FlowCollection::Flow &flow) { std::cout << flow << " "; });
  std::cout << std::endl;
  return 0;
}
