#pragma once

#include <SDL.h>
#include "./Draw.hpp"
#include "./HealthBar.hpp"

class Screen {

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
