#pragma once

#include "../headers/Screen.hpp"
#include "../headers/Button.hpp"
#include "../headers/startGameButton.hpp"
#include "../headers/quitGameButton.hpp"
#include "../headers/Player.hpp"
#include "../headers/Destructible.hpp"
#include "../classes/SoundManager.cpp"
#include "../headers/Draw.hpp" 


class inGameScreen :public Screen {

    Button* pauseGame;
    Button* quitGame;

    Player *player;
    std::vector<Draw*> background_objects;
    std::vector<Destructible*> destructibles;
    SoundManager soundManager;

    public:
    inGameScreen(SDL_Renderer*);
    ~inGameScreen();
    void render (SDL_Renderer*, SDL_Event, int*);

    void renderObjects(SDL_Renderer*);
    void addObjects(SDL_Renderer*);
    void createObstacles(SDL_Renderer*);
    void inputHandler(SDL_Event);
};