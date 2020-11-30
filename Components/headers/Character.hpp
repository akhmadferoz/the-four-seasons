#include "Draw.hpp"

class Character: public Draw{


    int maxLife;
    int score;

public:
    enum CharacterType {MainCharacter};
    Character(CharacterType, SDL_Rect, SDL_Renderer *);
    
}; 

