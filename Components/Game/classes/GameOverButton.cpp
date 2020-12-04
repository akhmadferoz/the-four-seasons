#include "../headers/GameOverButton.hpp"

GameOverButton::GameOverButton(SDL_Renderer *renderer) : Button(renderer) {}

/**
 * This function allows the user to interact with the game over button according to the coordinates of the button 
*/
int GameOverButton::onClick(SDL_Event e, int *whichscreen)
{
    int mouse_x{}, mouse_y{};
    switch (e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&mouse_x, &mouse_y);
        cout << mouse_x << ' ' << mouse_y << endl;
        if (mouse_x >= 700 &&
            mouse_y >= 300 &&
            mouse_x <= 700 + 200 &&
            mouse_y <= 300 + 100)
        {
            *whichscreen = -1;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        break;
    }
    return *whichscreen;
}

void GameOverButton::render()
{
    SDL_Rect *locationStart = new SDL_Rect({700, 300, 200, 100});
    SDL_Rect rects[] = {{0, 0, 551, 89}};
    std::vector<SDL_Rect *> assetLocations;

    for (SDL_Rect rect : rects)
    {
        SDL_Rect *imageLocation = new SDL_Rect(rect);
        assetLocations.push_back(imageLocation);
    }

    Image *image = new Image(assetLocations, "gameover.png");
    Draw *object = new Draw(gRenderer, image, locationStart);
    object->drawObject();
}

GameOverButton::~GameOverButton() {}
