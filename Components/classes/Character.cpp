#include "../headers/Character.hpp"

//---------------Constructors
Character::Character(Type type, SDL_Rect *location, SDL_Renderer *renderer)
{

    SDL_Rect rects[] = {{22, 20, 26, 41},
                        {87, 22, 25, 39},
                        {150, 20, 26, 41},
                        {212, 19, 27, 42},
                        {22, 84, 26, 41},
                        {89, 84, 24, 41},
                        {152, 85, 25, 40},
                        {212, 84, 26, 41},
                        {22, 148, 26, 41},
                        {86, 147, 24, 42}};

    std::vector<SDL_Rect *> assetLocations;
    for (SDL_Rect rect : rects)
    {
        SDL_Rect *imageLocation = new SDL_Rect(rect);
        assetLocations.push_back(imageLocation);
    }

    Image *image = new Image(assetLocations, "mon2_sprite_base.png");
    Draw::location = location;
    Draw::image = image;
    Draw::renderer = renderer;

    Draw::image->loadTexture(renderer);
}
