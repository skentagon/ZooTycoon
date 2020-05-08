
#ifndef SKENTAGON_ZOOTYCOON_ANIMAL_SEALION_HEADER_INCLUDED
#define SKENTAGON_ZOOTYCOON_ANIMAL_SEALION_HEADER_INCLUDED

#include "animal.hpp"
#include "age.hpp"

class BlackBear : public Animal {
  public:
    BlackBear() : Animal("Black Bear",cnt) {
      ++cnt;
    };
    static const int cost = 6000;
    static const int babyNum = 2;
    static const int foodCost = 3;
    static const int revenue = 600;
    static int cnt;

};

#endif