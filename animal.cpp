
#include "animal.hpp"

Animal::Animal( const std::string& s, int cost, int babyNum, int foodCost, int revenue, int type )
  : name( s ),
  cost(cost),
  babyNum(babyNum),
  foodCost(foodCost),
  revenue(revenue),
  type(type) {}

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
bool Animal::isBlackBear() const {
  return type == 0;
}
bool Animal::isSeaLion() const{
  return type == 1;
}
bool Animal::isTiger() const{ 
  return type == 2;
}

int Animal::getMedicalCost(){
  if ( age.getGeneration() == Age::generation::baby ){
    return cost;
  }
  return cost/2;
}

void Animal::setAge( int p ){
  age.setAge(p);
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