#include "../headers/inGameScreen.hpp"


inGameScreen::inGameScreen(SDL_Renderer* renderer) : Screen() {

    quitGame = new quitGameButton(renderer);

    image = new Image(NULL, "game_background_2.png");
}


void inGameScreen::render (SDL_Renderer* renderer, SDL_Event e, int* screenNumber) {

    // Draw Quit Button..
    SDL_Rect* locationQuit = new SDL_Rect({394, 514, 209, 102});
    quitGame -> render(renderer, locationQuit);

    // Change screenNumber depending on User Click
    *screenNumber = quitGame -> onClick(e, screenNumber);

    renderObjects(renderer);

}

inGameScreen::~inGameScreen() {
    delete quitGame;
    delete image;    
}



void inGameScreen::inputHandler(SDL_Event e) {
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT ) {
        player -> move = Player::RIGHT;
    }
    if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_RIGHT ) {
        player -> move = Player::NONE;
    }

    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT ) {
        player -> move = Player::LEFT;
    }
    if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_LEFT ) {
        player -> move = Player::NONE;
    }

    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_UP ) {
    
        player -> jump();
        soundManager.playEffect(SoundManager::JUMP);
    }

    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE ) {
    
        player -> attack();
        soundManager.playEffect(SoundManager::ATTACK);
    }	
}




void inGameScreen::addObjects(SDL_Renderer* gRenderer)
{
	SDL_Rect *location = new SDL_Rect({100, 700, 48, 84});
	Character *character = new Character(Character::MainCharacter, location, gRenderer);
	player = new Player(character);

	Image *image = new Image(NULL, "game_background_2.png");
	Draw *bg = new Draw(NULL, gRenderer, image);

	background_objects.push_back(bg);
}

void inGameScreen::createObstacles(SDL_Renderer* gRenderer)
{
	static int count = 0;
	int freq = rand() % 100;
	if (count % 10 == 0 && freq < 60)
	{
		Destructible *des = new Destructible(Destructible::Zombie, gRenderer);
		destructibles.push_back(des);
	}
	count += 1;
}

void inGameScreen::renderObjects(SDL_Renderer* gRenderer)
{

	//for (int x =0; x< 4;x++){

	//}
	createObstacles(gRenderer);

	
	for (Draw *object : inGameScreen::background_objects)
	{
		object->drawObject();
	}

	vector<int> invalidObjects;
	for (int x=0; x<destructibles.size();x++)
	{
		Destructible *object = destructibles[x];
		if (object -> isInValid()){
			invalidObjects.push_back(x);
			// destructibles.
			// delete object;
			continue;
		}

		object->drawObject();
		if(object  -> didCollide(player -> character)){
			std::cout <<"THE ENDDDD"<< endl;
		}
		
	}

	for(int index: invalidObjects){
		Destructible *object = destructibles[index];
		delete object;
		destructibles.erase(destructibles.begin()+ index);
	}

	player->render();
}