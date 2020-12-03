#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif


class Destructible: public Draw{

public:
    int speed = 20;
    enum Type {Zombie};
    void drawObject();
    Destructible(Type, SDL_Renderer *);
    bool isInValid();
};