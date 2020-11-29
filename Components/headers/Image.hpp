#include "../Structures/Coordinates.cpp"

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <list>


class Image
{

    int width, height;
    std::list<Coordinates> coordinates;
    std::string name = "";
    std::string basePath = "./Assets/images/";

    SDL_Texture *texture = NULL;

    bool animating = false;
    int animationIndex = 0;


public:
    SDL_Rect currentRect = {0,0,0,0};



    void loadTexture(SDL_Renderer *gRenderer );
    Image(Coordinates coordinates, int width, int height);
    Image(Coordinates coordinates, int width, int height, std::string name);
    
    void getAssetRectangle();
    
    SDL_Texture *getTexture();
};