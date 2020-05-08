
#include "animal.hpp"

Animal::Animal( const std::string& s, int cost, int babyNum, int foodCost, int revenue, bool isSeaLion_ )
  : name( s ),
  cost(cost),
  babyNum(babyNum),
  foodCost(foodCost),
  revenue(revenue),
  isSeaLion_(isSeaLion_) {}

int Animal::getCost() const {
  return cost;
}
int Animal::getBabyNum() const {
  return babyNum;
}
int Animal::getFoodCost() const {
  return foodCost;
}
int Animal::getRevenue() const {
  return revenue;
}
bool Animal::isSeaLion() const{
  return isSeaLion_;
}

int Animal::getMedicalCost(){
  if ( age.getGeneration() == Age::generation::baby ){
    return cost;
  }
  return cost/2;
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

void Animal::grow(){
  ++age;
}