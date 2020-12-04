
#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif

#pragma once
#include "./Screen.hpp"

#include "./Button.hpp"

#include "./NewGameButton.hpp"

#include "./QuitButton.hpp"

class Menu :public Screen {

    Button* newGame;
    Button* quitGame;

    public:
    Menu(SDL_Renderer *);

    void inputHandler(SDL_Event, int*);
    void renderObjects();
    void addObjects();

    ~Menu();

};