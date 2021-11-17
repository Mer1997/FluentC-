#include <iostream>
#include <vector>
#include <ranges>
using namespace std;

class Location {
  public:
    double distanceTo(const Location &other) const;
};

class GeographicalAttributes {
  public:
    Location getLocation() const;
};

class City {
  public:
    GeographicalAttributes const& getGeographicalAttributes() const;
};

//old func without expressive
auto computeNumberOfBreaks(const std::vector<City> &route) -> int {

  static const double max_distance = 100;

  int nBreaks = 0;
  for(auto it = route.begin(), it2 = route.end(); it != route.end(); it2 = it, ++it) {
    if(it2 != route.end()) {
      if(it->getGeographicalAttributes().getLocation().distanceTo(
            it2->getGeographicalAttributes().getLocation()) > max_distance) {
        ++nBreaks;
      }
    }
  }
  
  return nBreaks;
}

class FartherThan {
  public:
    explicit FartherThan(double distance): m_distance(distance){}
    bool operator() (const std::pair<City, City> &cities) {
      return cities.first.getGeographicalAttributes().getLocation().distanceTo(
          cities.second.getGeographicalAttributes().getLocation()) > m_distance;
    }
  private:
    double m_distance;
};

auto consecutive(const std::vector<City> &route) -> ranges<City>;

//new version
auto computeNumberOfBreaksNew(const std::vector<City> &route) -> int {
    
  static const double max_distance = 100;

  //consecutive 暂无实现, 类似 range, 代替 begin()、 end()
  return count_if(consecutive(route), FartherThan(max_distance));
}

auto main(void) -> int {

  static_assert(false, "实现不完全，无法通过编译");
  
  return 0;
}
