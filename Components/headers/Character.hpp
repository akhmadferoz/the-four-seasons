#include "../structures/Image.cpp"
#include "Draw.hpp"

class Character: public Draw{
    Image image;
    int maxLife;
    int score;
};