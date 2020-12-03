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

bool Draw::didCollide(Draw *obj){
    auto objLocation = obj -> location;
    if(objLocation->x >= location -> x && objLocation->x <= location -> x + location->w){
        return objLocation->y >= location -> y && objLocation->y <= location -> y + location->h;
    }



std:: cout << "LOCATIONS: - "<< endl ;
    printLocation();
    obj -> printLocation();
    return false;
}

Draw::Draw(){}


Draw::~Draw(){
    std::cout << "BYEEEE" << std::endl;
}

void Draw::printLocation(){
       std::cout << "xPos: " << location -> x << " yPos: " << location-> y  << " Width: " << location->w << " Height: " << location->h << endl; 
 
}