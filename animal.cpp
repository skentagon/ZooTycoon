
#include "animal.hpp"

int Animal::getMedicalCost(){
  if ( age.getGeneration() == Age::generation::baby ){
    return cost;
  }
  return cost/2;
}

void Animal::grow(){
  ++age;
}

void Animal::printName() const {
  std::cout << name;
}

void Animal::printAge() const {
  printName();
  std::cout << "\t:\t";
  age.print();
  std::cout << std::endl;
}

Age::generation Animal::getGeneration() {
  return age.getGeneration();
}