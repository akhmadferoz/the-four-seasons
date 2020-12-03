#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif


class Life: public Draw{

    public:
        void drawObject();
        
        Life(SDL_Renderer *, SDL_Rect *loc);


};