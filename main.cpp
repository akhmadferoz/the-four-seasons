#include "./Components/headers/Game.hpp"

int main(int argc, char *argv[]){
    Game game;
    srand(time(NULL));
    if( !game.init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
	

    game.run();
    game.close();

    return 0;
}
GameState *GameState::instance = 0;
