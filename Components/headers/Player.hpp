
#pragma once
#include "Character.hpp"


class Player{

public:
  enum MOVE{RIGHT, LEFT, NONE};
    int jumpTime = 3;
    int jumpingSeconds = -1;
    Character *character;
    MOVE move = NONE;

    Player(Character *);

    void render();
    
    void jump();
    void attack();

};