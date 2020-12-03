#include "../headers/Character.hpp"

//---------------Constructors
Character::Character(Type type, SDL_Rect *location, SDL_Renderer *renderer)
{

    SDL_Rect rects[] = {{9, 42, 15, 22},
{41, 41,15,22},
{72, 42, 16, 22}


};




    std::vector<SDL_Rect *> assetLocations;
    for (SDL_Rect rect : rects)
    {
        SDL_Rect *imageLocation = new SDL_Rect(rect);
        assetLocations.push_back(imageLocation);
    }

    Image *image = new Image(assetLocations, "characters.png");
    Draw::location = location;
    Draw::image = image;
    Draw::renderer = renderer;

    Draw::image->loadTexture(renderer);
}
