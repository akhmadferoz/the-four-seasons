#pragma once
#include "Button.hpp"

class QuitButton: public Button {
    public:
    QuitButton(SDL_Renderer*);
    void render();
    int onClick(SDL_Event, int* );
    ~QuitButton();
};