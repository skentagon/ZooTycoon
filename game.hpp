
#ifndef SKENTAGON_ZOOTYCOON_GAME_HEADER_INCLUDED
#define SKENTAGON_ZOOTYCOON_GAME_HEADER_INCLUDED

#include "zoo.hpp"

class Game {
  public:
    Game();
    void execute();
    bool shouldExit() const { return sw_exit; }
    void calcFeedCost();
  private:
    void events();
    void getRevenue();
    void buyAnimals();
    void payCost();
    Zoo zoo;
    bool sw_exit = false;
    long long bank = 100000;
    long long feedCost = 80;
    int sickRate = 4;
};

#endif