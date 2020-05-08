
#ifndef SKENTAGON_ZOOTYCOON_ZOO_HEADER_INCLUDED
#define SKENTAGON_ZOOTYCOON_ZOO_HEADER_INCLUDED

#include "animal.hpp"

class Zoo {
  public:
    ~Zoo();
    void grow();
    Animal* getAnimal( unsigned int i ) { return &animals[i]; }
    unsigned int getAminalNum() const { return animalNum; }
  private:
    Animal* animals = nullptr;
    unsigned int animalNum = 0;
};

#endif