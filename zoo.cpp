
#include "zoo.hpp"
#include "animal.hpp"

Zoo::~Zoo(){
  delete[] animals;
}

void Zoo::push( Animal a ){
  ++animalNum;
  Animal* temp = new Animal[animalNum];
  for( int i=0; i<animalNum-1; ++i ){
    temp[i] = animals[i];
  }
  temp[animalNum-1] = a;
  delete[] animals;
  animals = temp;
}

void Zoo::pop( int dx ){
  --animalNum;
  Animal* temp = new Animal[animalNum];
  int tdx = 0;
  for( int i=0; i<animalNum+1; ++i ){
    if ( dx == i )continue;
    temp[tdx] = animals[i];
    ++tdx;
  }
  delete[] animals;
  animals = temp;
}