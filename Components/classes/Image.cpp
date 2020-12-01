#include "../headers/Image.hpp"

//---------------Constructors
    Image::Image(SDL_Rect *coordinates)
    {
        this->coordinates.push_back(coordinates);
        

    }
    Image::Image(SDL_Rect *coordinates, std::string name):Image(coordinates){
        this -> name = name;

    }

    Image::Image(std::vector<SDL_Rect *> coordinates, std::string name) {
        this -> coordinates = coordinates;
        this -> name = name;
    }

//---------------Destructors
Image::~Image(){
    SDL_DestroyTexture(texture);

    //Delete all coordinates SDL_Rects
    for (SDL_Rect *rect: coordinates){
        delete rect;
    }
}



//---------------Getters

    SDL_Texture *Image::getTexture(){
        return Image::texture;
    }

    SDL_Rect *Image::getAssetRectangle(){
       // std::cout << "kkkkk" << std::endl;
        if (Image::animating){
           
             auto coordinates = Image::coordinates[ animationIndex % this -> coordinates.size()];
                     animationIndex += 1;
        std::cout << "ANIAMTING" << std::endl;
        return coordinates;

        }

        auto coordinates = Image::coordinates[0];
        return coordinates;
    }


//---------------Functions
    void Image::loadTexture(SDL_Renderer *gRenderer )
    {
        std::string path = Image::basePath + Image::name;
        std::cout << "PATH: " << path << std::endl;
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

