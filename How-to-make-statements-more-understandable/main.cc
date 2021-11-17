#include <iostream>
using namespace std;
class Item;

/* GuideLine:
 * Write them as close as possible to their specification
 * */

// The method doesn't respect the guideline of writing the if statement as close to the spec as possible
void Item::applyDiscount()
{
  if (!hasRedTag() && isSoldOnlineOnly()) {
    if (hasSpecialDayDiscount()) {
      price_ = std::max(minimumPrice, price_ - getSpecialDayDiscount());
    }
  } else if (!hasRedTag()) {
    price_ *= 1 - getSaleDiscount();
  }
}

// respect the guideline
void Item::applyDiscount()
{
  if (!hasRedTag()) {
    if (isSoldOnlineOnly()) {
      if (hasSpecialDayDiscount()) {
        price_ = std::max(minimumPrice, price_ - getSpecialDayDiscount());
      }
    } else {
      price_ *= 1 - getSaleDiscount();
    }
  }
}

/*对于 if 语句的可读性和扁平化需要权衡，尽可能保留其可读性*/

auto main(void) -> int
{
  static_assert(false, "Can't compile, not implement.");

  return 0;
}
