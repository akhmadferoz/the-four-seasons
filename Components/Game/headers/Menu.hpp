
#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif

#pragma once
#include "./Screen.hpp"

#include "./Button.hpp"

#include "./NewGameButton.hpp"

#include "./QuitButton.hpp"

/**
 * \brief This Menu class has the implementation of the main menu that the user sees before the game starts
 * 
*/

class Menu :public Screen{

    Button* newGame;
    Button* quitGame;
    public:
    Menu(SDL_Renderer *);

    void inputHandler(SDL_Event, int*);
    void renderObjects();
    void addObjects();

    ~Menu();
};