#include "../headers/PauseScreen.hpp"

void PauseScreen::addObjects()
{


	Image *image = new Image(NULL, "scroll.jpeg");
	Draw *bg = new Draw(gRenderer, image, NULL);

    continueGame = new ContinueButton(gRenderer);
    // quitGame = new QuitButton(gRenderer);

	background = bg;
}

void PauseScreen::renderObjects()
{
    background -> drawObject();

    continueGame -> render();
    // quitGame -> render();
}

void PauseScreen::inputHandler(SDL_Event e, int* whichScreen) {
    
    *whichScreen = continueGame -> onClick(e, whichScreen);
}


PauseScreen::PauseScreen(SDL_Renderer * renderer) : Screen(renderer) {
    addObjects();
}

PauseScreen::~PauseScreen(){
	//Delete all renderable objects
    delete background;
    background=nullptr;

    delete continueGame;
    continueGame=nullptr;
}