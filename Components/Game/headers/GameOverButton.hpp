#pragma once

#include "./Button.hpp"

/**
 * \brief This class contains the button for when the game has ended
*/

class GameOverButton :public Button {
    public:
    GameOverButton(SDL_Renderer*);
    void render();
    int onClick(SDL_Event, int* );
    ~GameOverButton();
};