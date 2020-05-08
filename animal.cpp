
#include "animal.hpp"

int Animal::getMedicalCost(){
  if ( age.getGeneration() == Age::generation::baby ){
    return cost;
  }
  return cost/2;
}

void Animal::printAge() const {
  printName();
}