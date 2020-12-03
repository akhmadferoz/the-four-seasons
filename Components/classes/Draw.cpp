
#include "../headers/Draw.hpp"


Draw::Draw() {}

Draw::Draw(SDL_Rect* coordinates) {
    this -> location = coordinates;
}

Draw::Draw(SDL_Renderer* gRenderer) {
    this -> renderer = gRenderer;
}


Draw::Draw(SDL_Rect *location, SDL_Renderer *renderer, Image *image){
    this -> renderer = renderer;
    this -> image = image;
    this -> location = location;
    image -> loadTexture(renderer);
}    


void Draw::drawObject(){
    SDL_RenderCopy(Draw::renderer, (Draw::image -> getTexture()), (Draw::image -> getAssetRectangle()), location);
}

void Draw::drawObject(SDL_Rect* src , SDL_Renderer* gRenderer , Image* pic ) {
    image -> loadTexture(renderer);
    SDL_RenderCopy(renderer, (pic -> getTexture()), (pic-> getAssetRectangle()), src);
};


bool Draw::didCollide(Draw *obj){
    auto objLocation = obj -> location;
    if(objLocation->x >= location -> x && objLocation->x <= location -> x + location->w){
        return objLocation->y >= location -> y && objLocation->y <= location -> y + location->h;
    }
    return false;
}


Draw::~Draw(){
    delete location;
    delete image;
    delete renderer;
}
