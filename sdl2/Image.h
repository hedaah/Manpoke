#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

class Image {

private:

    SDL_Surface * m_surface;
    
    SDL_Texture * m_texture;

    bool m_hasChanged;


public:
    Image () ;
    Image (const Image& im ) { std::cout<<"consttructeur par copie : ne devrait pas passer ici"<<std::endl; }
    const Image& operator=(const Image& im) const { std::cout<<"operator= par copie : ne devrait pas passer ici"<<std::endl; }
    ~Image();
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};

#endif