
#ifndef SKENTAGON_ZOOTYCOON_UTIL_HEADER_INCLUDED
#define SKENTAGON_ZOOTYCOON_UTIL_HEADER_INCLUDED

#include <string>

namespace util {
  std::string getUniqueString( int p ){
    std::string s;
    while(p) {
      s.push_back('a'+p%26);
      p/=26;
    };
    return s;
  }
}

#endif