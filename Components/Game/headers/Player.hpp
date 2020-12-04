#pragma once

#ifndef CHARACTER
#define CHARACTER
#include "Character.hpp"
#endif

/**
 * \brief This is the player class that deals with a specific player and its movement.
 * 
 * It also contains a character parameter and an airTime along with a jumping seconds parameter to deal with the physics of this game.
*/

class Player{
  public:
    enum MOVE{RIGHT, LEFT, NONE};
    
    int airTime = 3;
    int jumpingSeconds = -1;

    Character *character;
    MOVE move = NONE;

    Player(Character *);

    void render();
    void jump();
    void attack();
    void runningAnimation();
    void danceAnimation();
};