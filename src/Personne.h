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
        int m_vie;
        unsigned short int m_internalMovingState;
        bool b_isMoving;

        Vect2D m_corps;
        Direction m_dir;

        Image im_sprite[4]; // chaque sprite possède une image pour chaque directions.
        Image im_sprites;
        
        SDL_Rect rect_spritesPart[4][4];
        SDL_Rect rect_spritePos;

    public: 
        Personne(); // constructeur, toutes les données membres à 0 et la direction en bas, ces données seront gérées par les classes Monstre et Personne qui héritent de cette classe.

        void regeneration();// vie regeneré 

        int getVie();
        void setVie(int x);
        void WORLVie(int x); // recupere ou perd de la vie


        double getPosX(); // récupère la position X de la personne.
        double getPosY(); // récupère la position Y de la personne.
        void setPos(double x, double y); // Définie la position de la personne.

        Vect2D getVect2D(); // recupere le vecteur de la personne

        Direction getDir(); // récupère la direction de la personne.
        void setDir(Direction dir); // définie la direction de la personne.

        void getMovingState(bool& isMoving, unsigned short int& internalMovingState);
        void setMovingState(const bool& isMoving, const unsigned short int& internalMovingState);
        unsigned short int getInternalMovingState();

        Image& getImageSprite();

        SDL_Rect* getTabSpritesRect(Direction dir);
        SDL_Rect& getRectPos();

        bool moveLeft(const Terrain & t); // déplacement vers la gauche
        bool moveRight(const Terrain & t); // déplacement vers la droite
        bool moveUp(const Terrain & t); // déplacement vers le haut
        bool moveDown(const Terrain & t); // déplacement vers le bas
};

#endif