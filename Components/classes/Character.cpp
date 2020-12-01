#include "../headers/Character.hpp"

//---------------Constructors
Character::Character(Type type, SDL_Rect *location, SDL_Renderer *renderer)
{

    SDL_Rect rects[] = {{34, 5, 15, 19},
{50, 5, 15, 19},
{66, 5, 15, 19},
{82, 5, 15, 19}
};

    std::vector<SDL_Rect *> assetLocations;
    for (SDL_Rect rect : rects)
    {
        SDL_Rect *imageLocation = new SDL_Rect(rect);
        assetLocations.push_back(imageLocation);
    }

    Image *image = new Image(assetLocations, "c_knight.png");
    Draw::location = location;
    Draw::image = image;
    Draw::renderer = renderer;

    Draw::image->loadTexture(renderer);
}
