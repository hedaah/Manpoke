#ifndef _JEU_H
#define _JEU_H

#include <stdlib.h>
#include <time.h>
#include <sstream>

#include "Dresseur.h"
#include "Terrain.h"
#include "monstre.h"
#include "../sdl2/Image.h"

using namespace std;

/**
@brief Un jeu (de pacman) = un terrain et un pacman
*/
class Jeu {

private :

	Terrain ter;
	Dresseur dres;
	Monstre* tab_monstre = new Monstre[10];

    SDL_Window * window;
    SDL_Renderer * renderer;


    TTF_Font * font;
    Image font_im;
    SDL_Color font_color;

    Mix_Chunk * sound;
    Mix_Chunk * pas;
    bool withSound;

    Image im_Menu[2];
    Image Im_score;
    Image Im_Pr;

    int score;
    string score_str;
    

    unsigned short int USInt_level;
    unsigned short int USInt_nbMonstre;

public :

    
    Jeu();
    ~Jeu();




    const Terrain& getConstTerrain () const;                        //< \brief accesseur nécesseaire pour l'affichage
    const Dresseur& getConstDresseur () const;                          //< \brief accesseur nécesseaire pour l'affichage
                                                                        //< \brief accesseur nécesseaire pour l'affichage
    int getNombreDeMonstre() const;                                 //< \brief accesseur nécesseaire pour l'affichage

    void actionsMonstre ();
    void actionClavier(const char touche);          //< \brief rend vrai si mange une pastille, faux sinon

    void gestionDeplacement(Personne& p);
    void gestionRendue(Personne& p);
    
    void setupRenderer(int state);

    //Fonctions affichage SDL
    void afficherInit();
    void afficherDetruit();
    void afficherBoucle();
    void afficher();

};

 


#endif
