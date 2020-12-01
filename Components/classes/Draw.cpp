#include "../headers/Draw.hpp"


Draw::Draw(SDL_Renderer *renderer, Image *image,  SDL_Rect *location){
    this -> renderer = renderer;
    this -> image = image;
    this -> location = location;
    image -> loadTexture(renderer);
}    


void Draw::drawObject(){
    SDL_RenderCopy(Draw::renderer, (Draw::image -> getTexture()), (Draw::image -> getAssetRectangle()), location);
    
}

Draw::Draw(){}


Draw::~Draw(){
    std::cout << "BYEEEE" << std::endl;
}