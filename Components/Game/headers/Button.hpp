#pragma once

#include "./Draw.hpp"


class Button {

    protected:
    SDL_Renderer* gRenderer;

    public:
    Button(SDL_Renderer*);
    virtual ~Button();
    virtual void render()=0;
    virtual int onClick(SDL_Event, int* )=0;

};