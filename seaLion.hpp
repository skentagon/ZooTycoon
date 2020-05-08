
#ifndef SKENTAGON_ZOOTYCOON_ANIMAL_SEALION_HEADER_INCLUDED
#define SKENTAGON_ZOOTYCOON_ANIMAL_SEALION_HEADER_INCLUDED

#include "animal.hpp"
#include "age.hpp"

class SeaLion : public Animal {
  public:
    SeaLion()
      : Animal("Sea Lion",800,1,1,120) {
        ++cnt;
      };
    bool isSeaLion = true;
    static int cnt;
  private:
    Age age;
    //std::string name;

};

#endif