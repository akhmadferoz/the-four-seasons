#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif

class HealthBar: public Draw{
    public:
        void drawObject();
        enum Type {FILLED, EMPTY};
        HealthBar(Type, SDL_Renderer *, int);
};