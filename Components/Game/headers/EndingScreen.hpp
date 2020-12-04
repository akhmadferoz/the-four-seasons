#pragma once

#include "./HealthBar.hpp"
#include "./Screen.hpp"
#include "./Button.hpp"
#include "./GameOverButton.hpp"

/**
 * \brief This class handles the ending screen for the game
*/

class EndingScreen :public Screen {

    Button* Gameover;
    public:
    EndingScreen(SDL_Renderer *);
    void inputHandler(SDL_Event, int*);
    void renderObjects();
    void addObjects();
    ~EndingScreen();
};