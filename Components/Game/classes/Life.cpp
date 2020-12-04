#include "../headers/Life.hpp"


void Life::drawObject(){
    Draw::drawObject();
}

Life::Life(SDL_Renderer *renderer, SDL_Rect *location){   
    Image *image = new Image(NULL, "heart_full.png");
    this -> location = location;
    Draw::location = location;
    Draw::image = image;
    Draw::renderer = renderer;
    Draw::image ->loadTexture(renderer);
}
