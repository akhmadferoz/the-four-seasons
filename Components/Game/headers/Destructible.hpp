#pragma once

#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif

/**
 * \brief This Destructible class inherits from the Draw class. It consists of both our Obstacles and our Health
 * 
 * This class allows different "destructible" items to be created within the game which may include
 * obstacles or powerups/healths.
*/
class Destructible: public Draw{
    public:
        enum Type {Obstacle,Health};
        Type type = Obstacle;
        int collided = false;
        void drawObject();
        Destructible(Type, SDL_Renderer *);
        bool isInValid();
        void onHit();
};