#include "../headers/Menu.hpp"

void Menu::addObjects()
{


	Image *image = new Image(NULL, "scroll.jpeg");
	Draw *bg = new Draw(gRenderer, image, NULL);

    newGame = new NewGameButton(gRenderer);
    // quitGame = new QuitButton(gRenderer);

	background = bg;

}



void Menu::renderObjects()
{
    background -> drawObject();

    newGame -> render();
    // quitGame -> render();
}

void Menu::inputHandler(SDL_Event e, int* whichScreen) {
    
    *whichScreen = newGame -> onClick(e, whichScreen);
}


Menu::Menu(SDL_Renderer * renderer) : Screen(renderer) {
    addObjects();
}

Menu::~Menu(){
	//Delete all renderable objects
    delete background;
    background=nullptr;

    delete newGame;
    newGame=nullptr;
    delete quitGame;
    quitGame=nullptr;
}