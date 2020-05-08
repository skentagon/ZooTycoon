
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
    //Animal& operator=(const Animal&) = default;
    void grow();
    void printName() const;
    void printAge() const;
    Age::generation getGeneration();
    int getMedicalCost();
    int cost;
    int babyNum;
    int foodCost;
    int revenue;
    bool isSeaLion = false;
  private:
    Age age;
    std::string name;

};

#endif