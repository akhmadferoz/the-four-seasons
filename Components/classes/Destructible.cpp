#include "../headers/Destructible.hpp"



Destructible::Destructible(Type type, SDL_Renderer *renderer){


    SDL_Rect *objectLocation = new SDL_Rect({1024, 700, 60, 60});
    
    Image *image = new Image(NULL, "d.png");

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