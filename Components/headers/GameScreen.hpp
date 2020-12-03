#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif


#include "../classes/GameState.cpp"
#include "../headers/Player.hpp"
#include "./HealthBar.hpp"


class GameScreen{


    Player *player;
    std::vector<Draw*> background_objects;
    std::vector<Destructible*> destructibles;

    HealthBar *healthBar;

    SDL_Renderer *gRenderer;


public:

    GameScreen(SDL_Renderer *);

    void inputHandler(SDL_Event e);
    void renderObjects();
    void addObjects();
    void createObstacles();

    ~GameScreen();
};