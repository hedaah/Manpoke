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

    Jeu ();

    const Terrain& getConstTerrain () const;                        //< \brief accesseur nécesseaire pour l'affichage
    const Dresseur& getConstPacman () const;                          //< \brief accesseur nécesseaire pour l'affichage
    const Monstre& getConstFantome () const;                        //< \brief accesseur nécesseaire pour l'affichage
    int getNombreDeMonstre() const;                                 //< \brief accesseur nécesseaire pour l'affichage

    void actionsMonstre ();
    bool actionClavier(const char touche);          //< \brief rend vrai si mange une pastille, faux sinon

};

#endif
