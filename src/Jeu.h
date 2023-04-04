#ifndef _JEU_H
#define _JEU_H

#include "Dresseur.h"
#include "Terrain.h"
#include "monstre.h"

/**
@brief Un jeu (de pacman) = un terrain et un pacman
*/
class Jeu {

private :

	Terrain ter;
	Dresseur dres;
	Monstre  tab[10];

public :

    Jeu();


    Terrain getConstTerrain () const;                        //< \brief accesseur nécesseaire pour l'affichage
    Dresseur getConstDresseur () const;                          //< \brief accesseur nécesseaire pour l'affichage
                                                                        //< \brief accesseur nécesseaire pour l'affichage
    int getNombreDeMonstre() const;                                 //< \brief accesseur nécesseaire pour l'affichage

    void actionsMonstre ();
    void actionClavier(const char touche);          //< \brief rend vrai si mange une pastille, faux sinon

};

 


#endif
