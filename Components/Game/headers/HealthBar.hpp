#pragma once

#include "./Life.hpp"
#include <vector>

/**
 * \brief This class handles the Health Bar being displayed in the game.
 * 
 * The parameters of this class are:
 * \param currentHealth : This is the players current health
 * \param interimSpace :  This is the space between each heart in the health bar
 * \param lives : This is the vector being used to dynamically store the hearts in the health bar
 * \param renderer : This is the renderer being used
*/
class HealthBar{
    int currentHealth = 0;
    int interimSpace = 30;
    vector<Life *> lives;
    SDL_Renderer *renderer;

    public:
        void lostLife();
        void gainedLife();
        bool isDead();
        void draw();
        HealthBar( SDL_Renderer *, int);
        ~HealthBar();
};