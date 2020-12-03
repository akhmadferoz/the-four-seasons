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

#include "../headers/GameScreen.hpp"


#ifndef DEFAULTS
#define DEFAULTS
#include "../structures/Constants.cpp"

#endif



class Game
{
    //Screen dimension constants
    const int SCREEN_WIDTH = Constants::SCREEN_WIDTH;
    const int SCREEN_HEIGHT = Constants::SCREEN_HEIGHT;

    //The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    //The window renderer
    SDL_Renderer *gRenderer = NULL;

    GameScreen *gamescreen;

    Mix_Music *bgMusic = NULL;
   


public:
	//GameState *gameState = gameState->getInstance();


    bool init();
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();

    

};
