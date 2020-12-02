#include <SDL_mixer.h>
#include <string>

class SoundManager{

    
    public:
    enum Effect {ATTACK, JUMP};

        void playEffect(Effect effect){
            
            char *name;
            switch (effect){
                case ATTACK:
                name = "./Assets/audio/attack.wav";
                break;
                case JUMP:
                name = "./Assets/audio/SFX_Jump_12.wav";
                break;
            }
           
            auto sound = Mix_LoadMUS(name);
            Mix_PlayMusic(sound, 1);
            
        }
           void playMusic(){
            auto sound = Mix_LoadMUS("./Assets/audio/snowflake-waltz.mp3");
           // Mix_PlayMusic(sound, 1);
            
        }
        
};