#pragma once

#include "../headers/Button.hpp"


Button::Button() {
    
}


Button::Button(SDL_Rect* location): Draw(location) {

}

Button::Button(SDL_Renderer* renderer): Draw(renderer) {

}

Button::Button(SDL_Rect* location, SDL_Renderer* renderer, Image* pic): Draw (location, renderer, pic)
{

}

Button::~Button() {

}

