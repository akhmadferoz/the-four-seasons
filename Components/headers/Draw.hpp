// Libraries
#include "string"
#include <iostream>

// namespaces
using namespace std;

// Includes
#include "../headers/Image.hpp"



class Draw
{



public:
    SDL_Rect location;
        Image *image;
    SDL_Renderer *renderer;
    
    Draw();
    Draw(SDL_Rect,Image *,SDL_Renderer *);
    void drawObject();
   // animateObjectTo(){}

    //Function to render the image
};