
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

  int tmp = rand()%4;

  if ( tmp == 0 ){
    // sick
    int sick = rand()%zoo.getAminalNum();
    zoo.getAnimal(sick)->printName();
    std::cout << " gets sick!" << std::endl;
    if ( zoo.getAnimal(sick)->getMedicalCost() <= bank ){
      bank -= zoo.getAnimal(sick)->getMedicalCost();
    } else {
      zoo.getAnimal(sick)->printName();
      std::cout << " dies!" << std::endl;
      zoo.pop(sick);
    }

  } else if ( tmp == 1 ) {
    // baby
    int adultNum = 0;
    for( int i=0; i<zoo.getAminalNum(); ++i ){
      if ( zoo.getAnimal(i)->getGeneration() == Age::generation::adult ){
        ++adultNum;
      }
    }

  } else if ( tmp == 2 ) {
    // boom
    for( int i=0; i<zoo.getAminalNum(); ++i ){
      if ( zoo.getAnimal(i)->isSeaLion() ){
        zoo.getAnimal(i)->printName();
        int bonus = 150 + rand()%251;
        std::cout << " gets extra bonus! [" << bonus << "$]"<< std::endl;
        bank += bonus;
      }
    }
  }

}

void Game::getRevenue(){
  //
}

void Game::buyAnimals(){
  //
}

void Game::payCost(){
  //
}