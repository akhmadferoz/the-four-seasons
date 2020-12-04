// Libraries
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <thread>
#include <SDL_thread.h>

#pragma once

#include "./Game/headers/GameScreen.hpp"
#include "./Game/headers/Screen.hpp"
#include "./Game/headers/Menu.hpp"
#include "./Game/headers/PauseScreen.hpp"
#include "./Game/headers/EndingScreen.hpp"

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = Constants::SCREEN_WIDTH;
    const int SCREEN_HEIGHT = Constants::SCREEN_HEIGHT;

    //The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    //The window renderer
    SDL_Renderer *gRenderer = NULL;

    Screen *gamescreen;
    Screen *StartingScreen;
    Screen *FinishingScreen;
    Screen *pausedScreen;

    Mix_Music *bgMusic = NULL;
    int whichScreen{};

public:
    bool init();
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();
};

