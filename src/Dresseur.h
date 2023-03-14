#ifndef _Dresseur_H
#define _Dresseur_H

#include "Vect2D.h"
#include "Personne.h"


class Dresseur{

    private :
        Personne dress; // le corps du dresseur
        Vect2D pokbeall[10]; // Stock pokeball du dresseur
        Vect2D v; // vitesse de deplacement
    
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