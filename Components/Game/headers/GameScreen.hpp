#pragma once

#ifndef DRAW
#define DRAW
#include "./Draw.hpp"

#endif


#include "../headers/Player.hpp"
#include "./HealthBar.hpp"
#include "./Screen.hpp"

#include "../headers/Destructible.hpp"


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
