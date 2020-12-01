// Includes
#include "../headers/Game.hpp"
#include <string>

bool Game::init()
{

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		printf("Warning: Linear texture filtering not enabled!");
	}

	//Create window
	gWindow = SDL_CreateWindow("The Years @ HU", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	//Create renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

	if (gRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	//Initialize renderer color
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	return true;
}

SDL_Texture *Game::loadTexture(std::string path)
{
	//Final Texture
	SDL_Texture *newTexture = NULL;

	//Load image present at specific path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Craete a texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Getting rid of the old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

bool Game::loadMedia()
{

	// assets = loadTexture("./Assets/images/mon2_sprite_base.png");
	// ground = loadTexture("./Assets/images/ground.png");
	// gTexture = loadTexture("./Assets/images/bgSow.png");
	bgMusic = Mix_LoadMUS("./Assets/audio/snowflake-waltz.mp3");

	// if (assets == NULL || gTexture == NULL || ground == NULL ){
	// 	printf("Unable to run due to error: %s\n", SDL_GetError());
	// 	return false;
	// }

	if (bgMusic == NULL)
	{
		printf("Unable to load music: %s \n", Mix_GetError());
		return false;
	}

	return true;
}

void Game::run()
{

	Game::addObjects();
	//bool quit;
	SDL_Event e;

	while (true)
	{

		//Handling the events
		while (SDL_PollEvent(&e) != 0)
		{

			//Check if user requests quit
			if (e.type == SDL_QUIT)
			{
				return;
			}
		}

		if (Mix_PlayingMusic() == 0)
		{
			//Play the music
			Mix_PlayMusic(bgMusic, 2);
		}

		SDL_RenderClear(gRenderer); //This removes each and everything from the renderer
		Game::renderObjects();
		//	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL); //This draws the background to the renderer
		//	SDL_RenderCopy(gRenderer, ground, NULL, NULL);
		//SDL_RenderCopy(gRenderer, player, &player_srcRect, &player_moverRect);
		//The objects shall be drawn here
		SDL_RenderPresent(gRenderer); //This displays the updated renderer
		SDL_Delay(200);
	}
}

void Game::addObjects()
{
	SDL_Rect *location = new SDL_Rect({100, 450, 48, 84});
	Character *character = new Character(gameMode.character, location, gRenderer);
	player = new Player(character);

	Image *image = new Image(NULL, "bgSow.png");
	Draw *bg = new Draw(gRenderer, image, NULL);

	background_objects.push_back(bg);
}

void Game::createObstacles()
{
	static int count = 0;
	int freq = rand() % 100;
	if (count % 20 == 0 && freq < 70)
	{
		Destructible *des = new Destructible(Destructible::Zombie, gRenderer);
		destructibles.push_back(des);
	}
	count += 1;
}

void Game::renderObjects()
{

	//for (int x =0; x< 4;x++){

	//}
	createObstacles();

	

	for (Draw *object : Game::background_objects)
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
	}

	for(int index: invalidObjects){
		Destructible *object = destructibles[index];
		delete object;
		destructibles.erase(destructibles.begin()+ index);
	}

	player->character->drawObject();
}

void Game::close()
{
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

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	Mix_FreeMusic(bgMusic);
	bgMusic = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}
