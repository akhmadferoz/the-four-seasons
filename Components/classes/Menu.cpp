#include "../headers/Menu.hpp"


Menu::Menu(SDL_Renderer* renderer) : Screen() {

    startGame = new startGameButton(renderer);
    quitGame = new quitGameButton(renderer);

    image = new Image(NULL, "menu.jpg");
}


void Menu::render (SDL_Renderer* renderer, SDL_Event e, int* screenNumber) {

	// Draw Menu Background..
	Draw *bg = new Draw(NULL, renderer, image);
    bg -> drawObject();

    // Draw Start Button..
    SDL_Rect* locationStart = new SDL_Rect({394, 394, 209, 102});
    startGame -> render(renderer, locationStart);

    // Draw Quit Button..
    SDL_Rect* locationQuit = new SDL_Rect({394, 514, 209, 102});
    quitGame -> render(renderer, locationQuit);

    // Change screenNumber depending on User Click
    *screenNumber = startGame -> onClick(e, screenNumber);
    *screenNumber = quitGame -> onClick(e, screenNumber);

}

void Menu::addObjects(SDL_Renderer*) {

}

Menu::~Menu() {
    delete startGame;
    delete image;    
}