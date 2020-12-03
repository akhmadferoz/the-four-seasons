#pragma once

#include "../headers/Button.hpp"


class startGameButton :public Button {

    public:
    startGameButton( SDL_Renderer*);
    ~startGameButton();
    void render(SDL_Renderer*, SDL_Rect*);
    int onClick(SDL_Event, int*);
};