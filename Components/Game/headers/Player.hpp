
#ifndef CHARACTER
#define CHARACTER
#include "Character.hpp"
#endif

class Player{

public:
  enum MOVE{RIGHT, LEFT, NONE};
    
    int airTime = 3;
    int jumpingSeconds = -1;

 // int speed = 20;

    Character *character;
    MOVE move = NONE;

    Player(Character *);

    void render();
    
    void jump();
    void attack();
    void runningAnimation();
    void danceAnimation();

};