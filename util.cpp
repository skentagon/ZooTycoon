
#include <string>
#include "util.hpp"

std::string util::getUniqueString( int p ){
  std::string s;
  while(p) {
    s.push_back('a'+p%26);
    p/=26;
  };
  return s;
}