// Libraries
#include "string"
#include <iostream>

#pragma once
using namespace std;

#include "../headers/Image.hpp"

class Draw
{

public:
    SDL_Rect *location;
    Image *image;
    SDL_Renderer *renderer;

    Draw(SDL_Rect*);
    Draw(SDL_Renderer* );

    Draw(SDL_Rect* , SDL_Renderer* , Image* );

    void drawObject(SDL_Rect* , SDL_Renderer* , Image* );  
   
    bool didCollide(Draw *obj);

    Draw();
    void drawObject();
    ~Draw();

};