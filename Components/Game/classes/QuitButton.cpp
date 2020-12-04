#pragma once

#include "../headers/QuitButton.hpp"


QuitButton::QuitButton(SDL_Renderer* renderer): Button(renderer) {

 
}

int QuitButton::onClick(SDL_Event e, int* whichscreen) {
    int mouse_x{}, mouse_y{};
    switch (e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&mouse_x, &mouse_y);
        cout << mouse_x << ' ' << mouse_y << endl;
        if (mouse_x >= 294 &&
            mouse_y >= 394 &&
            mouse_x <= 294 + 200 &&
            mouse_y <= 394 + 100)
        {
            *whichscreen=-1;
            
        }
        else {
            *whichscreen=0;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        break;
    }

    return *whichscreen;
}

void QuitButton::render() {
    SDL_Rect* locationStart = new SDL_Rect({294, 394, 200, 100});
    
    SDL_Rect rects[] = {{0, 0, 294, 69}};

    std::vector<SDL_Rect *> assetLocations;
    for (SDL_Rect rect : rects)
    {
        SDL_Rect *imageLocation = new SDL_Rect(rect);
        assetLocations.push_back(imageLocation);
    }

    Image* image = new Image(assetLocations, "quit.png");

    Draw *object = new Draw(gRenderer, image, locationStart);

    object -> drawObject();

}

QuitButton::~QuitButton() {
    
}
