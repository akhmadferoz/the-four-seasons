#include "../headers/Draw.hpp"


 Draw::Draw(SDL_Rect location,Image *image,SDL_Renderer *renderer){
     this -> location = location;
     this -> image = image;
     this -> renderer = renderer;


 }

void Draw::drawObject(){
   // Draw::image -> getAssetRectangle();
    SDL_Rect *displayOn = new SDL_Rect({100, 450, 48, 84});
    SDL_RenderCopy(Draw::renderer, (Draw::image -> getTexture()), (Draw::image -> getAssetRectangle()), displayOn);
    std::cout << "DRAWING " << (Draw::image -> getAssetRectangle() ->w) << endl;

}

Draw::Draw(){}