#include <SDL_mixer.h>
#include <string>

class SoundManager{
    SoundManager(){}
    
    public:
    enum Effect {ATTACK, JUMP, COLLIDE};

       static void playEffect(Effect effect){
            
            char *name;
            switch (effect){
                case ATTACK:
                name = "./Assets/audio/attack.wav";
                break;
                case JUMP:
                name = "./Assets/audio/SFX_Jump_12.wav";
                break;
                case COLLIDE:
                name = "./Assets/audio/cartoon-throw.wav";
                break;
            }
           
            auto sound = Mix_LoadMUS(name);
            Mix_PlayMusic(sound, 1);
            
        }

          static Mix_Music *playMusic(){
               auto sound = Mix_LoadMUS("./Assets/audio/champion.mp3");
                Mix_PlayMusic(sound, 1);

            return sound;
        }
        
};