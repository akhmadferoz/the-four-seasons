#pragma once

#include "../headers/Draw.hpp"
#include "../headers/Image.hpp"

class Button : public Draw {

    protected:
    Image *image = NULL;

    public:
    Button();
    Button(SDL_Rect*);
    Button(SDL_Renderer*);
    Button(SDL_Rect*, SDL_Renderer* , Image* );
    virtual ~Button();

    virtual void render(SDL_Renderer*, SDL_Rect*) = 0;
    virtual int onClick(SDL_Event, int*) = 0;

};