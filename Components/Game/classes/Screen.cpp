#include "../headers/Screen.hpp"


Screen::Screen(){
    gRenderer = NULL;
}

Screen::Screen(SDL_Renderer* renderer): gRenderer(renderer) {}

Screen::~Screen(){}
