#pragma once

#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif


class Destructible: public Draw{

public:
    enum Type {Obstacle,Health};
    Type type = Obstacle;
    //int speed = 20;
    int collided = false;
    void drawObject();
    Destructible(Type, SDL_Renderer *);
    bool isInValid();
    void onHit();
};