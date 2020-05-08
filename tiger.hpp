
#ifndef SKENTAGON_ZOOTYCOON_ANIMAL_TIGER_HEADER_INCLUDED
#define SKENTAGON_ZOOTYCOON_ANIMAL_TIGER_HEADER_INCLUDED

#include "animal.hpp"
#include "age.hpp"

class Tiger : public Animal {
  public:
    Tiger() : Animal("Tiger",cnt) {
      ++cnt;
    };
    static const int cost = 15000;
    static const int babyNum = 3;
    static const int foodCost = 5;
    static const int revenue = 1500;
    static int cnt;

};

#endif