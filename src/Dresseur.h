#ifndef _Dresseur_H
#define _Dresseur_H

#include "Vect2D.h"
#include "Personne.h"


class Dresseur : public Personne{

    private :
        Vect2D pokbeall[10]; // Stock pokeball du dresseur
        Vect2D v; // vitesse de deplacement
    
    public :

        Dresseur();// constructeur

        void attaquer(); // generations des degats

        void capturemonstre(); // lancer des pokeballs

};

#endif