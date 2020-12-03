#include "../headers/GameScreen.hpp"

void GameScreen::addObjects()
{
	SDL_Rect *location = new SDL_Rect({100, Constants::SCREEN_HEIGHT - 84, 48, 84});
	Character *character = new Character(Character::MainCharacter, location, gRenderer);
	player = new Player(character);

	Image *image = new Image(NULL, "city.png");
	Draw *bg = new Draw(gRenderer, image, NULL);
	background = bg;

	
	healthBar = new HealthBar( gRenderer, 6);
		
	
}

void GameScreen::createObstacles()
{
	static int count = 0;
	int freq = rand() % 100;
	if (count % 10 == 0 && freq < 75)
	{
		Destructible *des = new Destructible(Destructible::Zombie, gRenderer);
		destructibles.push_back(des);
	}
	
	count += 1;
}



void GameScreen::renderObjects()
{
	
	GameState *s = s->getInstance();
	s ->gameTime++;

	createObstacles();

	//cout << "Created Obstacles" << endl;

	background -> drawObject();

	// for (Draw *object : GameScreen::background_objects){
	// 	object->drawObject();
	// }


	healthBar -> draw();
	//	cout << "Rendered Health Bar" << endl;


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
			
			
      		//invalidObjects.push_back(x);

			std::cout <<"THE ENDDDD"<< endl;
			SoundManager::playEffect(SoundManager::COLLIDE);
		}
		
	}

		//cout << "Checked for invalid objects" << endl;


	for(int index: invalidObjects){
		//cout << "DELETING INDEX" << index << endl;
		//cout << "SIZE INDEX" << invalidObjects.size()<< endl;


		Destructible *object = destructibles[index];
		
		delete object;
	}

	if(invalidObjects.size() >0){
	destructibles.erase(destructibles.begin()+ invalidObjects[0],destructibles.begin() + invalidObjects[invalidObjects.size()-1]+1);
	}

	//cout << "RENDERING PLAYER" << endl;

	player->render();
	Draw *character = player -> character;

  		if (character -> location -> x >= Constants::SCREEN_WIDTH - character -> location -> w){
            //character -> location -> x -= Constants::SCREEN_WIDTH / 2;
           character -> printLocation();
		  adjustObjects();
            }
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
	//for (Draw *obj : background_objects)
	//{
		delete background;
//	}

	for (Destructible *obj : destructibles)
	{
		delete obj;
	}

	
	delete healthBar;
}
void GameScreen::adjustObjects(){
	//background -> location -> x -=  Constants::SCREEN_WIDTH / 2;
	//cout << "ADJUSTING" << endl;
	for(Draw *d : destructibles){
		//if (d == NULL){continue;}
		d -> location -> x -= Constants::SCREEN_WIDTH;}
	player -> character -> location -> x -=  Constants::SCREEN_WIDTH;
	placeObstacles();
		//cout << "ADJUSTED" << endl;

}

void GameScreen::placeObstacles()
{
	
	int freq = rand() % 5 + 1;
		int space = (Constants::SCREEN_WIDTH - 150) / freq;

	for(int x = 0; x < freq; x++){

		Destructible *des = new Destructible(Destructible::Zombie, gRenderer);
		des -> location -> x = (space * x); 
		destructibles.push_back(des);
	
	}
	
	
	
	
}