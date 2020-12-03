#include "../headers/HealthBar.hpp"


HealthBar::HealthBar(Type type, SDL_Renderer *renderer, int x){
    static int y = 0;
    y+=x;
    SDL_Rect *objectLocation = new SDL_Rect({50+y, 50, 16, 16});
    
    Image *image = new Image(NULL, "heart_full.png");

    this -> location = objectLocation;
    Draw::location = objectLocation;
    
    Draw::image = image;
    Draw::renderer = renderer;

    Draw::image ->loadTexture(renderer);
}

void HealthBar::drawObject(){
    Draw::drawObject();
}
