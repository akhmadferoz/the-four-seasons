#include "../headers/Character.hpp"


//---------------Constructors
Character::Character(Type type, SDL_Rect *location, SDL_Renderer *renderer){


    SDL_Rect *imageLocation = new SDL_Rect({86, 147, 24, 42});
    Image *image = new Image(imageLocation, "mon2_sprite_base.png");
    Draw::location = location;
    Draw::image = image;
    Draw::renderer = renderer;

     Draw::image ->loadTexture(renderer);
   
}



