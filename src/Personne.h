#ifndef _Personne_H
#define _Personne_H

#include "Vect2D.h"

    enum Direction{
        haut,
        bas,
        gauche,
        droite
    };

class Personne {
    private:
        Vect2D m_corps;
        int m_vie;

        Direction m_dir;

    public: 
        Personne(); // constructeur, toutes les données membres à 0 et la direction en bas, ces données seront gérées par les classes Monstre et Personne qui héritent de cette classe.

        void regeneration();// vie regeneré 

        int getVie();
        void setVie(int x);

        int getPosX(); // récupère la position X de la personne.
        int getPosY(); // récupère la position Y de la personne.
        void setPos(float x, float y); // Définie la position de la personne.

        Direction getDir(); // récupère la direction de la personne.
        void setDir(Direction dir); // définie la direction de la personne.

        void moveLeft(); // déplacement vers la gauche
        void moveRight(); // déplacement vers la droite
        void moveUp(); // déplacement vers le haut
        void moveDown(); // déplacement vers le bas
};

#endif