#pragma once

#include "../headers/Button.hpp"


class quitGameButton :public Button {

    public:
    quitGameButton( SDL_Renderer*);
    ~quitGameButton();
    void render(SDL_Renderer*, SDL_Rect*);
    int onClick(SDL_Event, int*);
};