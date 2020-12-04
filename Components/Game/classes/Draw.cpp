#include "../headers/Draw.hpp"

Draw::Draw(SDL_Renderer *renderer, Image *image,  SDL_Rect *location){
    this -> renderer = renderer;
    this -> image = image;
    this -> location = location;
    image -> loadTexture(renderer);
    renderer = renderer;
}    


void Draw::drawObject(){
    SDL_RenderCopy(Draw::renderer, (Draw::image -> getTexture()), (Draw::image -> getAssetRectangle()), location);
}

/**
 * This is the primary function of our game that checks collisions between two objects in the game
*/

bool Draw::didCollide(Draw *obj){
    
    SDL_Rect *rect1 = obj -> location;
    SDL_Rect *rect2 =  location;

    int left1 = rect1 -> x;
    int right1 = rect1 ->  x + rect1 -> w;
    int top1 = rect1 ->  y;
    int bottom1 = rect1 ->  y + rect1 -> h;

    int left2 = rect2 -> x;
    int right2 = rect2 -> x + rect2 ->w ;
    int top2 = rect2 -> y;
    int bottom2 = rect2 -> y + rect2 -> h;

    bool yPosSame =  (top1 >= top2 && top1 <= bottom2) ||  (top2 >= top1 && top2 <= bottom1);
    
    if(!yPosSame){return false;}
    if (right1 >= left2 && right1 <= right2){return true;}
    if (right2 >= left1 && right2 <= right1){return true;}
    if (left1  <= right2 && left1 >= left2){return true;}
    if (left2 - 25 <= right1 && left2 >= left1){return true;}

    return false;
}

Draw::Draw(){}

Draw::~Draw(){
    delete image;
    delete location;
}

void Draw::printLocation(){
       std::cout << "xPos: " << location -> x << " yPos: " << location-> y  << " Width: " << location->w << " Height: " << location->h << endl;
}

void Draw::changeImage(Image *img){
    delete image;
    image = img;
    img -> loadTexture(renderer);
}
