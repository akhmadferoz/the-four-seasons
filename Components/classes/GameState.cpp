


#include "../headers/Destructible.hpp"

#ifndef CHARACTER
#define CHARACTER
#include "../headers/Character.hpp"
#endif


class GameState{
    static GameState *instance;
    GameState() {}
public:
    static GameState *getInstance() {
      if (!instance)
      instance = new GameState;
      return instance;
   }

   
    Character::Type character = Character::MainCharacter;
    
};