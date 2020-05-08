
#include "age.hpp"

Age::generation Age::getGeneration(){
  if ( age < 6 ) return generation::baby;
  if ( age < 24 ) return generation::adolesence;
  return adult;
}

const Age Age::operator++(int){
  ++age;
  return *this;
}

const Age Age::operator++(){
  const Age tmp = *this;
  ++(*this);
  return tmp;
}