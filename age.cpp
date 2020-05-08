
#include <iostream>
#include "age.hpp"

Age::generation Age::getGeneration() const {
  if ( age < 6 ) return generation::baby;
  if ( age < 48 ) return generation::adolesence;
  return adult;
}

void Age::setAge( int p ){
  age = p;
}

const Age Age::operator++(){
  ++age;
  return *this;
}

const Age Age::operator++(int){
  const Age tmp = *this;
  ++(*this);
  return tmp;
}

void Age::print() const {
  std::cout << age << " months old";
}