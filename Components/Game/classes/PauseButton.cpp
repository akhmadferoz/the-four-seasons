#pragma once

#include "../headers/PauseButton.hpp"


PauseButton::PauseButton(SDL_Renderer* renderer): Button(renderer) {

 
}

int PauseButton::onClick(SDL_Event e, int* whichscreen) {
    int mouse_x{}, mouse_y{};
    switch (e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&mouse_x, &mouse_y);
        cout << mouse_x << ' ' << mouse_y << endl;
        if (mouse_x >= 700 &&
            mouse_y >= 300 &&
            mouse_x <= 700 + 100 &&
            mouse_y <= 300 + 50)
        {
            *whichscreen=3;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        break;
    }

    return *whichscreen;
}

void PauseButton::render() {
    SDL_Rect* locationStart = new SDL_Rect({700, 300, 100, 50});
    
    SDL_Rect rects[] = {{0, 0, 314, 69}};

    std::vector<SDL_Rect *> assetLocations;
    for (SDL_Rect rect : rects)
    {
        SDL_Rect *imageLocation = new SDL_Rect(rect);
        assetLocations.push_back(imageLocation);
    }

    Image* image = new Image(assetLocations, "start.png");

    Draw *object = new Draw(gRenderer, image, locationStart);

    object -> drawObject();

}

PauseButton::~PauseButton() {
    
}
