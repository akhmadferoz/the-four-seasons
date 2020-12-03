





class GameState{
    static GameState *instance;
    GameState() {}
public:

    int gameTime = 0;
    int maxHealth = 4;
    int difficultyRate = 0.5;


    static GameState *getInstance() {
      if (!instance)
      instance = new GameState;
      return instance;
    }

    int gameSpeed(){
        return 20 +(difficultyRate * gameTime);
    }

    
};
