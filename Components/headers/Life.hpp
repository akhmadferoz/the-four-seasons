#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif

class Life: public Draw{

    public:
        int speed = 15;
        enum Type {Heart};
        void drawObject();
        Life(Type, SDL_Renderer *);
        bool isInValid();
};