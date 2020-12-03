#include "../headers/GameScreen.hpp"

void GameScreen::addObjects()
{
	SDL_Rect *location = new SDL_Rect({100, Constants::SCREEN_HEIGHT - 84, 48, 84});
	Character *character = new Character(Character::MainCharacter, location, gRenderer);
	player = new Player(character);

	Image *image = new Image(NULL, "city.png");
	Draw *bg = new Draw(gRenderer, image, NULL);

	background_objects.push_back(bg);

	
	healthBar = new HealthBar( gRenderer, 6);
		
	
}

void GameScreen::createObstacles()
{
	static int count = 0;
	int freq = rand() % 100;
	if (count % 10 == 0 && freq < 70)
	{
		Destructible *des = new Destructible(Destructible::Zombie, gRenderer);
		destructibles.push_back(des);
	}
	
	count += 1;
}

void GameScreen::renderObjects()
{


	createObstacles();

	

	for (Draw *object : GameScreen::background_objects){
		object->drawObject();
	}


	healthBar -> draw();
	

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

		if(player -> character  -> didCollide(object)){
			
			healthBar -> lostLife();
			
      		invalidObjects.push_back(x);

			std::cout <<"THE ENDDDD"<< endl;
			SoundManager::playEffect(SoundManager::COLLIDE);
		}
		
	}

	for(int index: invalidObjects){
		Destructible *object = destructibles[index];
		delete object;
		destructibles.erase(destructibles.begin()+ index);
	}

	player->render();
}

void GameScreen::inputHandler(SDL_Event e) {
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
        SoundManager::playEffect(SoundManager::JUMP);
    }

    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE ) {
    
        player -> attack();
        SoundManager::playEffect(SoundManager::ATTACK);
    }	
}


GameScreen::GameScreen(SDL_Renderer * renderer){
    gRenderer = renderer;
    addObjects();
}

GameScreen::~GameScreen(){
    delete player;
	//Delete all renderable objects
	for (Draw *obj : background_objects)
	{
		delete obj;
	}

	for (Destructible *obj : destructibles)
	{
		delete obj;
	}

	
	delete healthBar;
}