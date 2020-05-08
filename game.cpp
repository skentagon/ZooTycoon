
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "game.hpp"
#include "animal.hpp"
#include "seaLion.hpp"
#include "blackBear.hpp"
#include "tiger.hpp"

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
  if (sw_exit) return;
  getRevenue();
  if (sw_exit) return;
  buyAnimals();
  if (sw_exit) return;
  payCost();
}

void Game::events(){
  if (!zoo.getAminalNum()) return;

  int tmp = rand()%sickRate;

  if ( tmp == 0 ){
    // sick
    int sick = rand()%zoo.getAminalNum();
    zoo.getAnimal(sick)->printName();
    std::cout << " gets sick!" << std::endl;
    if ( zoo.getAnimal(sick)->getMedicalCost() <= bank ){
      bank -= zoo.getAnimal(sick)->getMedicalCost();
      if ( bank < 0 ){
        std::cout << "You went brankrupt!" << std::endl;
        sw_exit = true;
        return;
      }
    } else {
      zoo.getAnimal(sick)->printName();
      std::cout << " dies!" << std::endl;
      zoo.pop(sick);
    }

  } else {
    tmp = rand()%3;
    if ( tmp == 0 ) {
      // baby
      int adultNum = 0;
      for( int i=0; i<zoo.getAminalNum(); ++i ){
        if ( zoo.getAnimal(i)->getGeneration() == Age::generation::adult ){
          ++adultNum;
        }
      }
      int tmp = rand()%adultNum;
      int parent;
      for( int i=0; i<zoo.getAminalNum(); ++i ){
        if ( zoo.getAnimal(i)->getGeneration() == Age::generation::adult ){
          if (!tmp){
            parent = i;
            break;
          }
          --tmp;
        }
      }
      zoo.getAnimal(parent)->printName();
      std::cout << " gives birth babies!" << std::endl;
      for( int i=0; i<zoo.getAnimal(i)->getBabyNum(); ++i ){
        if (zoo.getAnimal(i)->isBlackBear()){
          BlackBear t;
          zoo.push(t);
        } else if (zoo.getAnimal(i)->isTiger()){
          Tiger t;
          zoo.push(t);
        } else {
          SeaLion t;
          zoo.push(t);
        }
      }

    } else if ( tmp == 1 ) {
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

}

void Game::getRevenue(){
  for( int i=0; i<zoo.getAminalNum(); ++i ){
    zoo.getAnimal(i)->printName();
    std::cout << " generates revenue : " << zoo.getAnimal(i)->getRevenue() << "$"<< std::endl;
    bank += zoo.getAnimal(i)->getRevenue();
  }
}

void Game::buyAnimals(){
  std::cout << "Would you buy new animals?[Y/n]" << std::endl;
  std::string s;
  std::cin >> s;
  if ( s == "Y" || s == "y" || s == "yes" || s == "YES" ){
    std::cout << "Witch animals do you want?\n1: black bear\n2: sea lion\n3: tiger" << std::endl;
    int input;
    std::cin >> input;
    std::cout << "How many animals do you want? (1~2)" << std::endl;
    int num;
    std::cin >> num;
    if ( num <= 0 || 3 <= num ){
      std::cout << "[error] invailed input!" << std::endl;
    } else {
      if ( input == 1 ){
        for( int i=0; i<num; ++i ){
          BlackBear t;
          bank -= t.getCost();
          t.setAge(48);
          zoo.push(t);
        }
      } else if ( input == 2 ){
        for( int i=0; i<num; ++i ){
          SeaLion t;
          bank -= t.getCost();
          t.setAge(48);
          zoo.push(t);
        }
      } else if ( input == 3 ){
        for( int i=0; i<num; ++i ){
          Tiger t;
          bank -= t.getCost();
          t.setAge(48);
          zoo.push(t);
        }
      } else {
        std::cout << "[error] unknown input!" << std::endl;
        return;
      }
      if ( bank < 0 ){
        std::cout << "You went brankrupt!" << std::endl;
        sw_exit = true;
        return;
      }
    }
  }
}

void Game::payCost(){
  std::cout << "Witch food type do you want to feed?\n1: Regular\n2: Premium\n3: Cheap" << std::endl;
  int input;
  std::cin >> input;
  if ( input <= 0 || 4 <= input ){
    input = 1;
  }
  double times;
  if ( input == 1 ){
    times = 1.0;
    sickRate = 4;
  } else if ( input == 2 ){
    times = 2.0;
    sickRate = 8;
  } else {
    times = 0.5;
    sickRate = 2;
  }
  for( int i=0; i<zoo.getAminalNum(); ++i ){
    bank -= zoo.getAnimal(i)->getFoodCost()*times;
    if ( bank < 0 ){
      std::cout << "You went brankrupt!" << std::endl;
      sw_exit = true;
      return;
    }
  }
  calcFeedCost();
}

void Game::calcFeedCost(){
  int diff = 80 + rand()&41;
  feedCost = feedCost * diff / 100;
}