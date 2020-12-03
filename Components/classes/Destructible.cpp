#include "../headers/Destructible.hpp"



Destructible::Destructible(Type type, SDL_Renderer *renderer){


    SDL_Rect *objectLocation = new SDL_Rect({Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT - 60, 60, 60});
    
    Image *image = new Image(NULL, "o_lighthouse.png");

    this -> location = objectLocation;
    Draw::location = objectLocation;
    
    Draw::image = image;
    Draw::renderer = renderer;

    Draw::image ->loadTexture(renderer);
}

void Destructible::drawObject(){
    Draw::drawObject();
    location -> x -= speed;
}

bool Destructible::isInValid(){
    return location -> x  <= 0;
}