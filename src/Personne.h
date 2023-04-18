#ifndef _Personne_H
#define _Personne_H

#include "Vect2D.h"
#include "Terrain.h"
#include "../sdl2/Image.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

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

        Image im_sprite[4]; // chaque sprite possède une image pour chaque directions.
        

    public: 
        Personne(); // constructeur, toutes les données membres à 0 et la direction en bas, ces données seront gérées par les classes Monstre et Personne qui héritent de cette classe.

        void regeneration();// vie regeneré 

        int getVie();
        void setVie(int x);

        float getPosX(); // récupère la position X de la personne.
        float getPosY(); // récupère la position Y de la personne.
        void setPos(float x, float y); // Définie la position de la personne.

        Vect2D getVect2D(); // recupere le vecteur de la personne
        Direction getDir(); // récupère la direction de la personne.
        void setDir(Direction dir); // définie la direction de la personne.

        Image* getImageSprite();

        void moveLeft(const Terrain & t); // déplacement vers la gauche
        void moveRight(const Terrain & t); // déplacement vers la droite
        void moveUp(const Terrain & t); // déplacement vers le haut
        void moveDown(const Terrain & t); // déplacement vers le bas
};

#endif