// Libraries
#include "string"
#include <iostream>

// namespaces
using namespace std;

// Includes
#include "../headers/Image.hpp"

#ifndef DEFAULTS
#define DEFAULTS

#include "../../Constants.cpp"
#include "../classes/SoundManager.cpp"

#endif
#include "../classes/GameState.cpp"

// #ifndef GameState
// #define GameState
// #include "../classes/GameState.cpp"
// #endif



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




  