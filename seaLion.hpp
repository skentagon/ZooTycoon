
#ifndef SKENTAGON_ZOOTYCOON_ANIMAL_SEALION_HEADER_INCLUDED
#define SKENTAGON_ZOOTYCOON_ANIMAL_SEALION_HEADER_INCLUDED

#include "animal.hpp"
#include "age.hpp"

class SeaLion : public Animal {
  public:
    SeaLion()
      : Animal("Sea Lion",cnt) {
        ++cnt;
      };
    static const int cost = 800;
    static const int babyNum = 1;
    static const int foodCost = 1;
    static const int revenue = 120;
    static const bool isSeaLion = true;
    static int cnt;
  private:
    Age age;
    //std::string name;

};

#endif