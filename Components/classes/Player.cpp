#include "../headers/Player.hpp"

Player::Player(Character *chr){
    this -> character = chr;
}

void Player::render(){
    if (jumpingSeconds == 2){
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
    std::cout << "Jumping seconds "<< jumpingSeconds << std::endl;
    this -> character -> drawObject();
    
}

void Player::jump(){
    if (jumpingSeconds != -1){return;}
    character ->  location -> y -= 90;
    jumpingSeconds = 0;
}
