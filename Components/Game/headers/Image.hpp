
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include <iostream>


class Image
{
    SDL_Texture *texture = NULL;

 
    std::string name = "";
    std::string basePath = "./Assets/images/";

    std::vector<SDL_Rect *> coordinates;
    std::vector<SDL_Rect *> secondCoordinates;
    SDL_Rect *playAnimation();
    void endAnimation();


    bool animating = false;
    int animationIndex = 0;


public:
   // SDL_Rect currentRect = {0,0,0,0};

    bool isAnimationInjected();

    void loadTexture(SDL_Renderer *gRenderer );
    Image(SDL_Rect *coordinates);

    Image(std::vector<SDL_Rect *>,std::string name);

    Image(SDL_Rect *coordinates, std::string name);
    
    SDL_Rect *getAssetRectangle();
    SDL_Texture *getTexture();


    void animateImage(std::vector<SDL_Rect *>);
    ~Image();
};