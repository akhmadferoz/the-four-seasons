#include "../headers/Destructible.hpp"

Destructible::Destructible(Type type, SDL_Renderer *renderer)
{
    this -> type = type;

    SDL_Rect *objectLocation; 
    Image *image;
    //Image *image = new Image(NULL, "germ.png");

    if (type == Obstacle){

    objectLocation = new SDL_Rect({Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT - 80, 44, 60});
    SDL_Rect rects[] = {
        {126, 5, 15, 19},
        {110, 5, 15, 19},
        {94, 5, 15, 19},
        {78, 4, 15, 19}

    };

    std::vector<SDL_Rect *> assetLocations;
    for (SDL_Rect rect : rects)
    {
        SDL_Rect *imageLocation = new SDL_Rect(rect);
        assetLocations.push_back(imageLocation);
    }

    image = new Image(assetLocations, "badKnight.png");

    }else{
    objectLocation = new SDL_Rect({Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT - 80, 60, 60});

 image = new Image(NULL, "shield.png");

    }

    this->location = objectLocation;
    Draw::location = objectLocation;

    Draw::image = image;
    Draw::renderer = renderer;

    Draw::image->loadTexture(renderer);
}

void Destructible::onHit()
{
    collided = true;
    if (image->isAnimationInjected())
    {
        return;
    }

    SDL_Rect rects[] = {{126, 5, 15, 19},
                        {110, 5, 15, 19},
                        {94, 5, 15, 19},
                        {78, 4, 15, 19},
                        {55, 4, 22, 19}};

    std::vector<SDL_Rect *> assetLocations;
    for (SDL_Rect rect : rects)
    {
        SDL_Rect *imageLocation = new SDL_Rect(rect);
        assetLocations.push_back(imageLocation);
    }

    image->animateImage(assetLocations);
}

void Destructible::drawObject()
{
    Draw::drawObject();

    GameState *s = s->getInstance();

    location->x -= s->gameSpeed();
}

bool Destructible::isInValid()
{
    return location->x <= 0 || collided;
}