

#include "./Life.hpp"
#include <vector>

class HealthBar{
    int totalHealth = 0;
    int currentHealth = 0;
    
    vector<Life *> lives;

    public:
        void lostLife();
        void gainedLife();

        void draw();
        HealthBar(Life::Type, SDL_Renderer *, int);
        ~HealthBar();
};