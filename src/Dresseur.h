#ifndef _Dresseur_H
#define _Dresseur_H

#include "Vect2D.h"

class Dresseur {

    private :
        Vect2D position; // le corps du dresseur
        Vect2D pokbeall[10]; // Stock pokeball du dresseur
    
    public :

        Dresseur();// constructeur

        void DeplaGauche(); // vers la gauche

        void DeplaDroite(); // VERS LA DROITE

        void DeplaHaut(); // vers le Haut

        void DeplaBas(); // vers le Bas

        void attaquer(); // generations des degats

        void capturemonstre(); // lancer des pokeballs

};

#endif