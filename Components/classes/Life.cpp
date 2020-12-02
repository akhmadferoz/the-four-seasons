#include "../headers/Life.hpp"

Life::Life(Type type, SDL_Renderer *renderer){

    SDL_Rect *objectLocation = new SDL_Rect({1024, 700, 60, 60});

    Image *image = new Image(NULL, "health.png");

    this -> location = objectLocation;
    Draw::location = objectLocation;

    Draw::image = image;
    Draw::renderer = renderer;

    Draw::image ->loadTexture(renderer);
}

void Life::drawObject(){
    Draw::drawObject();
    location -> x -= speed;
}

bool Life::isInValid(){
    return false;
    //return location -> x  <= 0;
}