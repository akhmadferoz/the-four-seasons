#include "../headers/Image.hpp"


    Image::Image(Coordinates coordinates, int width, int height)
    {
        this->coordinates.push_back(coordinates);
        this->width = width;
        this->height = height;
    }
    Image::Image(Coordinates coordinates, int width, int height, std::string name):Image(coordinates,width,height){
        this -> name = name;

    }

    SDL_Texture *Image::getTexture(){
        return Image::texture;
    }

    void Image::getAssetRectangle(){
        if (Image::animating){
            //Add next image code
        }
        auto coordinates = Image::coordinates.front();
        Image::currentRect =  {(coordinates.x),(coordinates.y),Image::width, Image::height};
    }


    void Image::loadTexture(SDL_Renderer *gRenderer )
    {
        std::string path = Image::basePath + Image::name;
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
           // SDL_FreeSurface(loadedSurface);
        }
        Image::texture = newTexture;
    }

