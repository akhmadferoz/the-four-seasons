#pragma once
#include "Button.hpp"

class PauseButton: public Button {
    public:
    PauseButton(SDL_Renderer*);
    void render();
    int onClick(SDL_Event, int* );
    ~PauseButton();
};