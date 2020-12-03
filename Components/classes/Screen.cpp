#pragma once

#include "../headers/Screen.hpp"

Screen::Screen() {
    image = NULL;
}

Screen::Screen(Image* pic) : image(pic) {
    
}

Screen::~Screen() {
    delete image;
}


