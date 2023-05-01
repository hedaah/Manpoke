#ifndef _JEU_H
#define _JEU_H

#include <stdlib.h>
#include <time.h>
#include <sstream>

#include "Dresseur.h"
#include "Terrain.h"
#include "monstre.h"
#include "../sdl2/Image.h"
#include <vector>

using namespace std;

/**
@brief Un jeu (de pacman) = un terrain et un pacman
*/
class Jeu {

private :

	Terrain ter;
	Dresseur dres;
    std::vector<Monstre*> tab_monstres;
    // Utilisations simples : tab_monstres.pop_back() : enlève le dernier élément du tableau
    // tab_monstres.erase(i) : enlève l'élément i du tableau dynamique

    SDL_Window * window;
    SDL_Renderer * renderer;


    TTF_Font * font;
    Image font_im;
    Image font_point;
    SDL_Color font_color;

    Mix_Chunk * sound;
    Mix_Chunk * pas;
    bool withSound;

    Image im_Menu[2];
    Image Im_score;
    Image Im_Pr;

    int score;
    string score_str;

    int point;
    string point_str;
    

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
