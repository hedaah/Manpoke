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

    TTF_Font * font;

    bool withSound;

    Image im_Menu[2];
    Image Im_vie;

public :

    
    Jeu();




    const Terrain& getConstTerrain () const;                        //< \brief accesseur nécesseaire pour l'affichage
    const Dresseur& getConstDresseur () const;                          //< \brief accesseur nécesseaire pour l'affichage
                                                                        //< \brief accesseur nécesseaire pour l'affichage
    int getNombreDeMonstre() const;                                 //< \brief accesseur nécesseaire pour l'affichage

    void actionsMonstre ();
    void actionClavier(const char touche);          //< \brief rend vrai si mange une pastille, faux sinon
    
    void setupRenderer(int state);

    //Fonctions affichage SDL
    void afficherInit();
    void afficherDetruit();
    void afficherBoucle();
    void afficher();

};

 


#endif
