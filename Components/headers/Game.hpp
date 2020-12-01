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
#include "../classes/SoundManager.cpp"

class Game
{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 800;

    //The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    //The window renderer
    SDL_Renderer *gRenderer = NULL;

    //Current displayed texture
    // SDL_Texture *gTexture = NULL;
    // //global reference to png image sheets
    // SDL_Texture *assets = NULL;
    // SDL_Texture *ground = NULL;
    
  //  SDL_Rect const player_srcRect = {86, 147, 24, 42};
   // SDL_Rect const player_moverRect = {100, 450, 48, 84};

    Mix_Music *bgMusic = NULL;
    
    Player *player;
    std::vector<Draw*> background_objects;
    std::vector<Destructible*> destructibles;
    SoundManager soundManager;

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
