#pragma once

#include "../headers/quitGameButton.hpp"


quitGameButton::quitGameButton(SDL_Renderer* renderer): Button() {
    
    SDL_Rect rects[] = {{180, 155, 289, 102}};

    std::vector<SDL_Rect *> assetLocations;
    for (SDL_Rect rect : rects)
    {
        SDL_Rect *imageLocation = new SDL_Rect(rect);
        assetLocations.push_back(imageLocation);
    }

    image = new Image(assetLocations, "play.png");
}




int quitGameButton::onClick(SDL_Event e, int* screenNumber) {
    int mouse_x{}, mouse_y{};
    switch (e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&mouse_x, &mouse_y);
        cout << mouse_x << ' ' << mouse_y << endl;
        if (mouse_x >= 394 &&
            mouse_y >= 514 &&
            mouse_x <= 394 + 209 &&
            mouse_y <= 394 + 102)
        {
            *screenNumber = -1;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        break;
    }
    return *screenNumber;
}



void quitGameButton::render(SDL_Renderer* renderer, SDL_Rect* location) {

    image -> loadTexture(renderer);

    SDL_RenderCopy(renderer, image->getTexture(), image->getAssetRectangle(), location);

}

quitGameButton::~quitGameButton() {
    delete image;
}
