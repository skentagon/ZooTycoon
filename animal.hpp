
#ifndef SKENTAGON_ZOOTYCOON_ANIMAL_HEADER_INCLUDED
#define SKENTAGON_ZOOTYCOON_ANIMAL_HEADER_INCLUDED

#include <string>
#include <iostream>
#include "age.hpp"
#include "util.hpp"

class Animal {
  public:
    Animal() = default;
    Animal( const std::string& s, int cost, int babyNum, int foodCost, int revenue, bool isSeaLion_ = false );
    int getMedicalCost();
    int getCost() const;
    int getBabyNum() const;
    int getFoodCost() const;
    int getRevenue() const;
    bool isSeaLion() const;
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
    bool isSeaLion_;

};

#endif