#pragma once

#include <SDL.h>
#include "./Draw.hpp"
#include "./HealthBar.hpp"

/**
 * \brief This class is for the rendering of the different screens that we have in our game
*/

class Screen{

    protected:
    SDL_Renderer* gRenderer;
    Draw *background;

    public:
    Screen();
    Screen(SDL_Renderer*);
    virtual ~Screen();
    virtual void inputHandler(SDL_Event, int*)=0;
    virtual void addObjects()=0;
    virtual void renderObjects()=0;
};
