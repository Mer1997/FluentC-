#include "Frige.h"
#include "Engine.h"

class Frige::FrigeImpl
{
  public:
    void cooldown(std::string degree) {
      std::cout << "Now degree is " << degree << std::endl;
    }
  private:
    Engine engine_;
};

void Frige::cooldown(std::string degree) {
  _impl->cooldown(degree);
}

Frige::Frige(): _impl(new FrigeImpl) {}
Frige::~Frige() = default;

