#pragma once
// Libraries
#include "string"
#include <iostream>

using namespace std;
#include "../headers/Image.hpp"

#ifndef DEFAULTS
#define DEFAULTS

#include "../../Constants.cpp"
#include "../classes/SoundManager.cpp"

#endif
#include "../classes/GameState.cpp"

/**
 * \brief This is the Draw class that handles the rendering/drawing of each and every object onto the game screen
 *  
 * The Draw class has three basic parameters
 * \param location : the exact location of the image to be drawn
 * \param image : the image to be drawn
 * \param renderer : the renderer being used
*/

class Draw{
    public:
        SDL_Rect *location;
        Image *image;
        SDL_Renderer *renderer;
        Draw(SDL_Renderer *, Image *, SDL_Rect *);     
        void changeImage(Image *img);
        bool didCollide(Draw *obj);
        Draw();
        void drawObject();
        ~Draw();
        void printLocation();
};




  