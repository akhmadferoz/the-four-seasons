


#include <string>


class GameState{
    static GameState *instance;
    GameState() {}
public:

    int gameTime = 0;
    int maxHealth = 4;
    int difficultyRate = 0.98;

    int backgroundIndex = 0;

    std::string backgrounds[4] = {"City1.png","City2_pale.png","City3_pale.png","City4_pale.png"};

    static GameState *getInstance() {
      if (!instance)
      instance = new GameState;
      return instance;
    }

    int gameSpeed(){
        return 20 +(difficultyRate * gameTime);
    }

    
};
