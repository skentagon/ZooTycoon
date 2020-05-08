
#ifndef SKENTAGON_ZOOTYCOON_ANIMAL_HEADER_INCLUDED
#define SKENTAGON_ZOOTYCOON_ANIMAL_HEADER_INCLUDED

#include <string>
#include <iostream>
#include "age.hpp"
#include "util.hpp"

class Animal {
  public:
    Animal() = default;
    Animal( const std::string& s, int dx )
      : name( s + util::getUniqueString(dx) ) {}
    void grow(){ ++age; };
    void printName() const;
    void printAge() const;
    int getMedicalCost();
    const int cost = 0;
    static const int babyNum;
    static const int foodCost;
    static const int revenue;
    static const int medialcCost;
    static const bool isSeaLion = false;
  private:
    Age age;
    const std::string name;

};

#endif