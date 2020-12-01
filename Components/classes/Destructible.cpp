#include "../headers/Destructible.hpp"



Destructible::Destructible(Type type, SDL_Renderer *renderer){


    SDL_Rect *objectLocation = new SDL_Rect({1024, 450, 48, 84});
    
    Image *image = new Image(NULL, "o_lighthouse.png");

    this -> location = objectLocation;
    Draw::location = objectLocation;
    
    Draw::image = image;
    Draw::renderer = renderer;

     Draw::image ->loadTexture(renderer);
}

void Destructible::drawObject(){
    Draw::drawObject();
    std::cout << "YOOOOOOOO" << std::endl;
    location -> x -= speed;
}

bool Destructible::isInValid(){
    return location -> x  <= 0;
}