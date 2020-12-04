#pragma once
#include "Button.hpp"

class ContinueButton: public Button {
    public:
    ContinueButton(SDL_Renderer*);
    void render();
    int onClick(SDL_Event, int* );
    ~ContinueButton();
};