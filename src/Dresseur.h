#ifndef _Dresseur_H
#define _Dresseur_H

#include "Vect2D.h"
#include "Personne.h"


class Dresseur : public Personne{

    private :
        Vect2D pokeball[10]; // Stock pokeball du dresseur
        Vect2D v; // vitesse de deplacement
        bool lancer; //booleen pour gerer le lancer de pokeball
    
    public :

        Dresseur();// constructeur

        void LienPokD();

        bool getBol(); // recupere un booleen
        void setBolT();  //mettre le booleen true
        void setBolF(); // mettre le booleen false

        Vect2D getPoke(int entier); //recupere le vecteur
        int getPosXP(int entier); // récupère la position X des pokeballs.
        int getPosYP(int entier); // récupère la position Y de pokeballs.

        void attaquer(int entier); // generations des degats

        void capturemonstre(); // lancer des pokeballs

};

#endif