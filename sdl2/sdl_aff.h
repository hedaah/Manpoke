#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "../src/Jeu.h"

using namespace std;

class Image {

private:

    SDL_Surface * m_surface;
    
    SDL_Texture * m_texture;

    bool m_hasChanged;


public:
    Image () ;
    ~Image();
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};


class jeu {

private :

    Jeu game;

    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Renderer * menu;

    SDL_Rect positionMenu;

    TTF_Font * font;
    Image font_im;
    SDL_Color font_color;

    Mix_Chunk * sound;
    Mix_Chunk * pas;
    bool withSound;
    

    Image im_Menu;
    Image im_dresseur[4];
    Image im_pokeball;
    Image im_mur;
    Image im_herbe;
    Image im_porte;
    Image im_pierre;
    Image im_water;

public :

    jeu();
    void afficherInit();
    void afficherDetruit();
    void afficherBoucle();
    void afficher();

};