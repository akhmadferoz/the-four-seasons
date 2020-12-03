// Libraries
#include "string"
#include <iostream>

// namespaces
using namespace std;

// Includes
#include "../headers/Image.hpp"

#ifndef DEFAULTS
#define DEFAULTS
#include "../../structures/Constants.cpp"
#include "../classes/SoundManager.cpp"

#endif

class Draw
{


public:



    SDL_Rect *location;
    Image *image;
    SDL_Renderer *renderer;

    Draw(SDL_Renderer *, Image *, SDL_Rect *);     

   
    bool didCollide(Draw *obj);

    Draw();
    void drawObject();
    ~Draw();

    void printLocation();
};




  