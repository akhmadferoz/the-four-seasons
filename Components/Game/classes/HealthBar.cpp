#include "../headers/HealthBar.hpp"






HealthBar::HealthBar( SDL_Renderer *renderer, int max){

    int interimSpace = 30;
    
    for (int x =0; x< max; x++){
        

        SDL_Rect *objectLocation = new SDL_Rect({50+ (x*(interimSpace)) , 50, 25, 25});
        Life *life = new Life(renderer,objectLocation);
        lives.push_back(life);
       
    }

}

void HealthBar::lostLife(){
    if (lives.size() == 0){return;}
    delete lives[lives.size() -1];
    lives.erase(lives.end() - 1);
}

void HealthBar::draw(){
    for(Life *life : lives){
        life -> drawObject();
        
    }
    }
    
 HealthBar::~HealthBar(){
      for(Life *life : lives){
        delete life;
    }
 }