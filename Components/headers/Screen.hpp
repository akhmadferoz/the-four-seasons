#pragma once

#include <SDL.h>
#include "../headers/Image.hpp"


class Screen {

    protected:
    Image* image;

    public:
    Screen();
    Screen(Image*);
    virtual ~Screen();
    virtual void render (SDL_Renderer*, SDL_Event, int*) = 0;
    virtual void addObjects(SDL_Renderer*) = 0;

};