#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif

/**
 * \brief This is the Life class that inherits from the Draw class.
*/

class Life: public Draw{
    public:
        void drawObject();
        Life(SDL_Renderer *, SDL_Rect *loc);
};