
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include <iostream>


class Image
{

 
    std::vector<SDL_Rect *> coordinates;
    std::string name = "";
    std::string basePath = "./Assets/images/";

    SDL_Texture *texture = NULL;

    bool animating = false;
    int animationIndex = 0;


public:
   // SDL_Rect currentRect = {0,0,0,0};



    void loadTexture(SDL_Renderer *gRenderer );
    Image(SDL_Rect *coordinates);
    Image(SDL_Rect *coordinates, std::string name);
    
    SDL_Rect *getAssetRectangle();
    SDL_Texture *getTexture();


    ~Image();
};