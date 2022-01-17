#include <iostream>
#include <utility>
#include <memory>
using namespace std;
class Instructions;
using InstructionsUniquePtr = std::unique_ptr<Instructions, void(*)(Instructions*)>;

class Instructions
{
  public:
    virtual InstructionsUniquePtr clone() const = 0;
    virtual ~Instructions() {};
};

void deleteInstructions(Instructions* instructions){ delete instructions;}
void doNotDeleteInstructions(Instructions* instructions){}

class Sketch : public Instructions
{
  public:
    InstructionsUniquePtr clone() const {
      return InstructionsUniquePtr (new Sketch(*this), deleteInstructions);
    }
};

class Blueprint : public Instructions
{
  public:
    InstructionsUniquePtr clone() const {
      return InstructionsUniquePtr (new Blueprint(*this), deleteInstructions);
    }
};

class House
{
  public:
    explicit House(InstructionsUniquePtr instructions) : instructions_(std::move(instructions)) {}
    House(House const& other) : instructions_(other.instructions_->clone()) {}

  private:
    InstructionsUniquePtr instructions_;
};

enum class BuildingMethod
{
  fromSketch,
  fromBlueprint,
  other
};

auto InvalidBuildMethod() { return std::invalid_argument("InvalidBuildMethod"); }

House buildAHouse(BuildingMethod method)
{
  if (method == BuildingMethod::fromSketch)
    return House(InstructionsUniquePtr(new Sketch, deleteInstructions));
  if (method == BuildingMethod::fromBlueprint)
    return House(InstructionsUniquePtr(new Blueprint, deleteInstructions));
  throw InvalidBuildMethod();
}

auto main(void) -> int {

  Blueprint blueprint;
  House house(InstructionsUniquePtr(&blueprint, doNotDeleteInstructions));
  House house_clone(house);

  House house1 = buildAHouse(BuildingMethod::fromBlueprint);
  House house2 = buildAHouse(BuildingMethod::fromSketch);

  House house1_clone(house1);
  House house2_clone(house2);

  return 0;
}
