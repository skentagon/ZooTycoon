

#include "game.hpp"

int main(){
  Game game;
  while(!game.shouldExit()){
    game.execute();
  }
}