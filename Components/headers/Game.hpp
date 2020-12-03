// Libraries
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "../headers/Screen.hpp"
#include "../headers/Menu.hpp"
#include "../headers/inGameScreen.hpp"

class Game
{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 700;


    Screen* startingScreen;
    Screen* GameScreen;

    //The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    //The window renderer
    SDL_Renderer *gRenderer = NULL;

    //Current displayed texture
    SDL_Texture *gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture *assets = NULL;
    SDL_Texture *ground = NULL;
    
    int ScreenNumber;

    Mix_Music *bgMusic = NULL;

public:
    Game();
    ~Game();
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();

    void renderMenu();
    
    void renderObjects();
    void addObjects();
    void createObstacles();

};
