#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

using namespace std;


class jeu
{
    private :

   
    unsigned int dimx, dimy;        // les dimensions de l'image
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    SDL_Texture * m_texture ;
    SDL_Surface * m_surface ;
    bool m_hasChanged;

    public :

    void afficherBoucle();

    void afficherInit();

    void afficherDetruit();

    void afficher();




};
