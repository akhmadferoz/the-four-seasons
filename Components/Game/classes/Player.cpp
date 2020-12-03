#include "../headers/Player.hpp"

Player::Player(Character *chr){
    this -> character = chr;
}

void Player::render(){
 GameState *s = s->getInstance();

    if (jumpingSeconds == airTime){
        character -> location -> y += 90;
        jumpingSeconds = -1;
    }
    
    if (jumpingSeconds != -1){
        jumpingSeconds += 1;
        }


    if (move == RIGHT){
      
        character -> location -> x += s -> gameSpeed();
    } 

     if (move == LEFT){
        if (character -> location -> x <= 0){
           
            return;}
       
        character -> location -> x -= s -> gameSpeed();
    }   
    this -> character -> drawObject();
   
   if (move == RIGHT){
           runningAnimation();

   }
}

void Player::jump(){
    if (jumpingSeconds != -1){return;}
    SoundManager::playEffect(SoundManager::JUMP);

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

void Player::runningAnimation(){
    if(character -> image -> isAnimationInjected()){return;}

    SDL_Rect rects[] = {{425, 42, 15, 22},
{457, 41, 15, 22},
{489, 42, 15, 22},
{520, 41, 17, 22},
{522, 42, 16, 22}
};

    std::vector<SDL_Rect *> assetLocations;
    for (SDL_Rect rect : rects)
    {
        SDL_Rect *imageLocation = new SDL_Rect(rect);
        assetLocations.push_back(imageLocation);
    }
    
    character -> image -> animateImage(assetLocations);
}


void Player::danceAnimation(){
        if(character -> image -> isAnimationInjected()){return;}

    SDL_Rect rects[] = {
 {9, 12, 15, 20},
{41, 11, 15, 20},
{72, 12, 16, 20},
{104, 11, 17, 20},
{135, 13, 17, 19},
{168, 11, 16, 20},
{201, 11, 15, 20},
{233, 13, 16, 19},
{294, 12, 17, 20},
{329, 12, 15, 20},
{361, 12, 15, 20},
{393, 12, 15, 20},
{426, 12, 13, 20},
{457, 11, 15, 20},
{489, 12, 15, 20},
{520, 11, 17, 20},
{552, 12, 16, 20},
{584, 12, 15, 20},
{616, 12, 15, 20},
{648, 12, 15, 20},
{680, 12, 15, 20},
{711, 12, 17, 20}
};

    std::vector<SDL_Rect *> assetLocations;
    for (SDL_Rect rect : rects)
    {
        SDL_Rect *imageLocation = new SDL_Rect(rect);
        assetLocations.push_back(imageLocation);
    }
    
    character -> image -> animateImage(assetLocations);
}