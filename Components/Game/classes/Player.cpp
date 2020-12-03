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

