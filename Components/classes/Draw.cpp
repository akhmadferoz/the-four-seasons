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
    // auto objLocation = obj -> location;
    // if(objLocation->x >= location -> x && objLocation->x <= location -> x + location->w){
    //     return objLocation->y >= location -> y && objLocation->y <= location -> y + location->h;
    // }

    SDL_Rect *rect1 = obj -> location;
    SDL_Rect *rect2 =  location;


    int left1 = rect1 -> x;
    int right1 = rect1 ->  x + rect1 -> w;
    int top1 = rect1 ->  y;
    int bottom1 = rect1 ->  y + rect1 -> h;

    int left2 = rect2 -> x;
    int right2 = rect2 -> x + rect2 ->w;
    int top2 = rect2 -> y;
    int bottom2 = rect2 -> y + rect2 -> h;

    if (top1 <= top2){return false;}
    if (top1 >= bottom2){return false;}
    if (right1 <= left2){return false;}
    if (left1 >= right2){return false;}
    return true;



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