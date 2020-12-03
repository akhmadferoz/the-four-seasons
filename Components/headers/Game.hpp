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

#include "../classes/GameState.cpp"
#include "../headers/Player.hpp"

#ifndef DEFAULTS
#define DEFAULTS
#include "../structures/Constants.cpp"
#include "../classes/SoundManager.cpp"
#include "../headers/HealthBar.hpp"

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



    Mix_Music *bgMusic = NULL;
    
    Player *player;
    std::vector<Draw*> background_objects;
    std::vector<Destructible*> destructibles;

    std::vector<HealthBar*> healths;



public:
	//GameState *gameState = gameState->getInstance();


    bool init();
    bool loadMedia();
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();
    void renderObjects();
    void addObjects();
    void createObstacles();
    

};
