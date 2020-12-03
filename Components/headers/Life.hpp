#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif


class Life: public Draw{

    public:
        void drawObject();
        enum Type {FILLED, EMPTY};
        Life(Type, SDL_Renderer *, SDL_Rect *loc);


};