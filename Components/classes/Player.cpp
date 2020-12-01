#include "../headers/Player.hpp"

Player::Player(Character *chr){
    this -> character = chr;
}

void Player::render(){
    if (jumpingSeconds == jumpTime){
        character -> location -> y += 90;
        jumpingSeconds = -1;
    }
    
    if (jumpingSeconds != -1){
        jumpingSeconds += 1;
        }


    if (move == RIGHT){
        character -> location -> x += 20;
    } 

     if (move == LEFT){
        character -> location -> x -= 20;
    }   
    this -> character -> drawObject();
    
}

void Player::jump(){
    if (jumpingSeconds != -1){return;}
    character ->  location -> y -= 90;
    jumpingSeconds = 0;
}

void Player::attack(){


    SDL_Rect rects[] = {{32, 97, 15, 19},
{50, 98, 24, 18},
{78, 98, 27, 18}
};

    std::vector<SDL_Rect *> assetLocations;
    for (SDL_Rect rect : rects)
    {
        SDL_Rect *imageLocation = new SDL_Rect(rect);
        assetLocations.push_back(imageLocation);
    }

    character -> image -> animateImage(assetLocations);
}

