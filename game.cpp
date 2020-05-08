
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "game.hpp"
#include "animal.hpp"
#include "seaLion.hpp"

Game::Game(){
  srand((unsigned)time(nullptr));
}

void Game::execute(){
  std::cout << "========================================\n"
    << "Bank Balance : " << bank << std::endl;
  for( int i=0; i<zoo.getAminalNum(); ++i ){
    zoo.getAnimal(i)->grow();
    zoo.getAnimal(i)->printAge();
  }
  events();
  getRevenue();
  buyAnimals();
  payCost();
}

void Game::events(){
  if (!zoo.getAminalNum()) return;

  switch( rand()%4 ){
    case 0: // sick
      int sick = rand()%zoo.getAminalNum();
      break;

    case 1: //baby

    case 2: //boom
      for( int i=0; i<zoo.getAminalNum(); ++i ){
        if ( zoo.getAnimal(i)->isSeaLion ){}
      }
      break;

    default: //nothing

  }

}

void Game::getRevenue(){}
void Game::buyAnimals(){}
void Game::payCost(){}