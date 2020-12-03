#include "../headers/Timer.hpp"


Timer::Timer(){
    startTicks = 0;
    running = false;
}

void Timer::start(){
    running = true;
    startTicks = SDL_GetTicks();
}

int Timer::ticks(){
    if (running == true){
        return SDL_GetTicks() - startTicks;
    }
    return 0;
}

bool Timer::status(){
    return running;
}
