#pragma once
#include "Button.hpp"

/**
 * \brief This class deals with the new game option/button when the geme starts
*/

class NewGameButton: public Button {
    public:
    NewGameButton(SDL_Renderer*);
    void render();
    int onClick(SDL_Event, int* );
    ~NewGameButton();
};