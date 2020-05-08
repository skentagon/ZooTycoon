
#ifndef SKENTAGON_ZOOTYCOON_ANIMAL_HEADER_INCLUDED
#define SKENTAGON_ZOOTYCOON_ANIMAL_HEADER_INCLUDED

#include <string>
#include <iostream>
#include "age.hpp"
#include "util.hpp"

class Animal {
  public:
    Animal() = default;
    Animal( const std::string& s, int cost, int babyNum, int foodCost, int revenue, int type );
    int getMedicalCost();
    int getCost() const;
    int getBabyNum() const;
    int getFoodCost() const;
    int getRevenue() const;
    void setAge( int p );
    bool isBlackBear() const;
    bool isSeaLion() const;
    bool isTiger() const;
    void printName() const;
    void printAge() const;
    Age::generation getGeneration();
    void grow();
  private:
    Age age;
    std::string name;
    int cost;
    int babyNum;
    int foodCost;
    int revenue;
    int type;
    /*
      0: blackBear
      1: seaLion
      2: tiger
    */

};

#endif