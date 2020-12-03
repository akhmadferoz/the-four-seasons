// Includes
#include "../headers/Game.hpp"
#include <string>


Game::Game() {
	ScreenNumber = 0;
	startingScreen = new Menu(gRenderer);
	GameScreen = new inGameScreen(gRenderer);
}

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


	return true;
}

void Game::run()
{
	
	GameScreen -> addObjects(gRenderer);

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

			SDL_RenderClear(gRenderer);

			if (ScreenNumber == -1) {
				return;
			}

			if (ScreenNumber == 0) {
				startingScreen -> render(gRenderer,e, &ScreenNumber);
			}

			if (ScreenNumber == 1) {
				SDL_RenderClear(gRenderer);
				GameScreen -> render(gRenderer, e, &ScreenNumber);
			}	
			
		}

		if (Mix_PlayingMusic() == 0)
		{
			//Play the music
			//Mix_PlayMusic(bgMusic, 2);
			// soundManager.playMusic();
		}


		
		SDL_RenderPresent(gRenderer); 
		SDL_Delay(200);
	
}
}



void Game::close()
{

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


Game::~Game() {
	delete startingScreen;

}