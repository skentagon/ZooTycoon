
#ifndef SKENTAGON_ZOOTYCOON_ANIMAL_HEADER_INCLUDED
#define SKENTAGON_ZOOTYCOON_ANIMAL_HEADER_INCLUDED

#include <string>
#include <iostream>
#include "age.hpp"
#include "util.hpp"

class Animal {
  public:
    Animal() = default;
    Animal( const std::string& s, int cost, int babyNum, int foodCost, int revenue )
      : name( s ),
      cost(cost),
      babyNum(babyNum),
      foodCost(foodCost),
      revenue(revenue) {}
    void grow();
    void printName() const;
    void printAge() const;
    int getMedicalCost();
    const int cost;
    const int babyNum;
    const int foodCost;
    const int revenue;
    const bool isSeaLion = false;
  private:
    Age age;
    const std::string name;

};

#endif