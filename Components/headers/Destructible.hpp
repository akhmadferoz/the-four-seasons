#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif

class Destructible: public Draw{

public:
    int speed = 10;
    enum Type {Zombie};
    void drawObject();
    Destructible(Type, SDL_Renderer *);
    bool isInValid();
};