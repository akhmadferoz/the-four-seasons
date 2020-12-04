#pragma once
#include "Button.hpp"

class NewGameButton: public Button {
    public:
    NewGameButton(SDL_Renderer*);
    void render();
    int onClick(SDL_Event, int* );
    ~NewGameButton();
};