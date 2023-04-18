#ifndef _JEU_H
#define _JEU_H

#include "Dresseur.h"
#include "Terrain.h"
#include "monstre.h"
#include "../sdl2/Image.h"

/**
@brief Un jeu (de pacman) = un terrain et un pacman
*/
class Jeu {

private :

	Terrain ter;
	Dresseur dres;
	Monstre  tab[10];

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

public :

    
    Jeu();




    const Terrain& getConstTerrain () const;                        //< \brief accesseur nécesseaire pour l'affichage
    const Dresseur& getConstDresseur () const;                          //< \brief accesseur nécesseaire pour l'affichage
                                                                        //< \brief accesseur nécesseaire pour l'affichage
    int getNombreDeMonstre() const;                                 //< \brief accesseur nécesseaire pour l'affichage

    void actionsMonstre ();
    void actionClavier(const char touche);          //< \brief rend vrai si mange une pastille, faux sinon

    //Fonctions affichage SDL
    void afficherInit();
    void afficherDetruit();
    void afficherBoucle();
    void afficher();

};

 


#endif
