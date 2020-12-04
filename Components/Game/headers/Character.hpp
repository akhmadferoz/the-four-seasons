#pragma once

#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif
#include <vector>

/**
 * \brief This is the Character class that inherits from the Draw class. It consists of the main character of the game
 * 
 * \param The maxLife parameter refers to the maximum life of the character
*/

class Character: public Draw{
    int maxLife;

    public:
        enum Type {MainCharacter};
        Character(Type, SDL_Rect *, SDL_Renderer *);
}; 

