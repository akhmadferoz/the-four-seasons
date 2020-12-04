#include "../headers/EndingScreen.hpp"

void EndingScreen::addObjects()
{


	Image *image = new Image(NULL, "scroll.jpeg");
	Draw *bg = new Draw(gRenderer, image, NULL);

    Gameover = new GameOverButton(gRenderer);
    // quitGame = new QuitButton(gRenderer);

	background = bg;

}



void EndingScreen::renderObjects()
{
    background -> drawObject();

    Gameover -> render();
}

void EndingScreen::inputHandler(SDL_Event e, int* whichScreen) {
    
    *whichScreen = Gameover -> onClick(e, whichScreen);
}


EndingScreen::EndingScreen(SDL_Renderer * renderer) : Screen(renderer) {
    addObjects();
}

EndingScreen::~EndingScreen(){
	//Delete all renderable objects
    delete background;
    background=nullptr;

    delete Gameover;
    Gameover=nullptr;

}