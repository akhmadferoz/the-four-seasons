#pragma once

#include "./Button.hpp"



class GameOverButton :public Button {

    public:
    GameOverButton(SDL_Renderer*);
    void render();
    int onClick(SDL_Event, int* );
    ~GameOverButton();

};