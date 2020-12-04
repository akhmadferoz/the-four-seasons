#pragma once
#include "Button.hpp"

/**
 * \brief This contains the button for the Quit Game option
*/

class QuitButton: public Button {
    public:
    QuitButton(SDL_Renderer*);
    void render();
    int onClick(SDL_Event, int* );
    ~QuitButton();
};