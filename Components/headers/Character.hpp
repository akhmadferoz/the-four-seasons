#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif

class Character: public Draw{


    int maxLife;
    int score;

public:
    enum Type {MainCharacter};
    Character(Type, SDL_Rect *, SDL_Renderer *);

    
}; 

