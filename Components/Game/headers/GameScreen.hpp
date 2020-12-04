#pragma once

#ifndef DRAW
#define DRAW
#include "./Draw.hpp"

#endif


#include "../headers/Player.hpp"
#include "./HealthBar.hpp"
#include "./Screen.hpp"
#include "../headers/Destructible.hpp"

/**
 * \brief This class is of the main game screen while the player is playing the game. It inherits from the Screen class.
 *
 * The prameters used in this class are:
 * \param player : this is the player that the game is currently being played with 
 * \param destructibles : these are the objects in the game
 * \param healthBar : this is the health bar of the character
 * \param gameClock : this is the clock being used for the game
*/

class GameScreen : public Screen{
    Player *player;
    //std::vector<Draw*> background_objects;
    std::vector<Destructible*> destructibles;
    HealthBar *healthBar;
    int gameClock = 1;

public:
    GameScreen(SDL_Renderer *);
    void inputHandler(SDL_Event , int*);
    void renderObjects();
    void addObjects();
    void createObstacles();
    void placeObstacles();
    void adjustObjects();
    ~GameScreen();
};
