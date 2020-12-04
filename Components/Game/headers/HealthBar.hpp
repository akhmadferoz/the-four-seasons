#pragma once

#include "./Life.hpp"
#include <vector>

class HealthBar{
    int totalHealth = 0;
    int currentHealth = 0;
     int interimSpace = 30;
    vector<Life *> lives;

    SDL_Renderer *renderer;

    public:
        void lostLife();
        void gainedLife();

        void draw();
        HealthBar( SDL_Renderer *, int);
        ~HealthBar();
};