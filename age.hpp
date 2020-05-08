
#ifndef SKENTAGON_ZOOTYCOON_AGE_HEADER_INCLUDED
#define SKENTAGON_ZOOTYCOON_AGE_HEADER_INCLUDED

class Age {
  public:
    enum generation {
      baby,
      adolesence,
      adult,
    };
    generation getGeneration() const;
    void setAge( int p );
    const Age operator++(int);
    const Age operator++();
    void print() const;
  private:
    int age;
};

#endif