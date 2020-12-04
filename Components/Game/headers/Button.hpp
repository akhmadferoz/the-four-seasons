#pragma once

#include "./Draw.hpp"

/**
 * \brief This class handles the button interface with the game
 * 
 * \param gRenderer : This allows the button to be rendered onto the game screen
 * This class makes use of polymorphism.
*/

class Button{
    protected:
    SDL_Renderer* gRenderer;

    public:
    Button(SDL_Renderer*);
    virtual ~Button();
    virtual void render()=0;
    virtual int onClick(SDL_Event, int* )=0;
};