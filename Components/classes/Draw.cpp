#include "../headers/Draw.hpp"

void Draw::drawObject(){
    Draw::image -> getAssetRectangle();
    SDL_RenderCopy(Draw::renderer, (Draw::image -> getTexture()), &(Draw::image -> currentRect), NULL);
}