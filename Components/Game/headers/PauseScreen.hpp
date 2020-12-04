
#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif

#pragma once
#include "./Screen.hpp"

#include "./Button.hpp"

#include "./ContinueButton.hpp"

class PauseScreen :public Screen {

    Button* continueGame;

    public:
    PauseScreen(SDL_Renderer *);

    void inputHandler(SDL_Event, int*);
    void renderObjects();
    void addObjects();

    ~PauseScreen();

};