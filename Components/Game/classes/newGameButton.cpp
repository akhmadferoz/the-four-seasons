#pragma once

#include "../headers/NewGameButton.hpp"


NewGameButton::NewGameButton(SDL_Renderer* renderer): Button(renderer) {

 
}

int NewGameButton::onClick(SDL_Event e, int* whichscreen) {
    int mouse_x{}, mouse_y{};
    switch (e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&mouse_x, &mouse_y);
        cout << mouse_x << ' ' << mouse_y << endl;
        if (mouse_x >= 294 &&
            mouse_y >= 194 &&
            mouse_x <= 294 + 200 &&
            mouse_y <= 194 + 100)
        {
            *whichscreen=1;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        break;
    }

    return *whichscreen;
}

void NewGameButton::render() {
    SDL_Rect* locationStart = new SDL_Rect({294, 194, 200, 100});
    
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

NewGameButton::~NewGameButton() {
    
}
