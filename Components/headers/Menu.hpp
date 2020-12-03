#pragma once

#include "../headers/Screen.hpp"
#include "../headers/Button.hpp"
#include "../headers/startGameButton.hpp"
#include "../headers/quitGameButton.hpp"

class Menu :public Screen {

    Button* startGame;
    Button* quitGame;

    public:
    Menu(SDL_Renderer*);
    ~Menu();
    void render (SDL_Renderer*, SDL_Event, int*);
    void addObjects(SDL_Renderer*);

};