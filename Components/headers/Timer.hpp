#ifndef DRAW
#define DRAW
#include "./Draw.hpp"
#endif


class Timer{
    int startTicks;
    bool running;
    public:
        Timer();
        void start();
        int ticks();
        bool status();
};