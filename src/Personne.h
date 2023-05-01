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

/**
    * @class Personne
    * @brief Module qui représente une personne dans le jeu.
    * Cette classe gère les déplacements et les interactions de la personne.
*/
class Personne {
    private:
        int m_vie; ///< La vie de la personne.
        unsigned short int m_internalMovingState; ///< Etat interne de mouvement.
        bool b_isMoving; ///< Indique si la personne est en train de bouger.

        Vect2D m_corps; ///< Position de la personne.
        Direction m_dir; ///< Direction de la personne.

        Image im_sprite[4]; ///< Tableau d'images pour chaque direction de la personne.
        Image im_sprites; ///< Image globale contenant tous les sprites de la personne.

        SDL_Rect rect_spritesPart[4][4]; ///< Tableau de rectangles pour chaque partie du sprite.
        SDL_Rect rect_spritePos; ///< Position du sprite.
    public: 
        /**
        * @brief Constructeur par défaut de la classe Personne.
        * Toutes les données membres sont initialisées à 0 et la direction est en bas.
        */
        Personne(); 

        /**
        * @brief Régénère la vie de la personne.
        */
        void regeneration();

        /**
        * @brief Récupère la vie de la personne.
        * @return La vie de la personne.
        */
        int getVie();

         /**
        * @brief Définit la vie de la personne.
        * @param x La nouvelle valeur de vie de la personne.
        */
        void setVie(int x);

        /**
        * @brief Récupère ou perd de la vie.
        * @param x La valeur de vie à récupérer ou à perdre.
        */
        void WORLVie(int x); 

        /**
        * @brief Récupère la position en X de la personne.
        * @return La position en X de la personne.
        */
        double getPosX();

        /**
        * @brief Récupère la position en Y de la personne.
        * @return La position en Y de la personne.
        */
        double getPosY(); 

        /**
        * @brief Définit la position de la personne.
        * @param x La nouvelle position en X de la personne.
        * @param y La nouvelle position en Y de la personne.
        */
        void setPos(double x, double y); 

          /**
        * @brief Récupère le vecteur de la personne.
        * @return Le vecteur de la personne.
        */
        Vect2D getVect2D(); 


         /**
        * @brief Récupère la direction de la personne.
        * @return La direction de la personne.
        */
        Direction getDir();

          /**
        * @brief Définit la direction de la personne.
        * @param dir La nouvelle direction de la personne.
        */
        void setDir(Direction dir); 

         /**
         * @brief Recuperer l'état de déplacement de la personne.
        * @param isMoving La variable qui va stocker si la personne est en mouvement ou non.
        * @param internalMovingState La variable qui va stocker l'état de mouvement interne de la personne.
        */
        void getMovingState(bool& isMoving, unsigned short int& internalMovingState);

         /**
        * @brief recuperre l'état de déplacement de la personne.
        * @param isMoving Si la personne est en mouvement ou non.
        * @param internalMovingState L'état de mouvement interne de la personne.
        */
        void setMovingState(const bool& isMoving, const unsigned short int& internalMovingState);

         /**
        * @brief Renvoie l'état de mouvement interne de la personne.
        * @return L'état de mouvement interne de la personne.
        */
        unsigned short int getInternalMovingState();

        /**
        * @brief Renvoie l'image de sprite de la personne.
        * @return L'image de sprite de la personne.
        */
        Image& getImageSprite();

        /**
        * @brief Renvoie le rectangles de sprite pour une direction donnée.
        * @param dir La direction pour laquelle on veut récupérer le tableau de rectangles de sprite.
        * @return Le rectangles du tableau de sprite pour la direction donnée.
        */
        SDL_Rect* getTabSpritesRect(Direction dir);

        /**
        * @brief Renvoie le rectangle de position du sprite de la personne.
        * @return Le rectangle de position du sprite de la personne.
        */
        SDL_Rect& getRectPos();


        /**
        * @brief Déplace la personne vers la gauche si possible.
        * @param t Le terrain sur lequel la personne se déplace.
        * @return true si le déplacement a été effectué, false sinon.
        */
        bool moveLeft(const Terrain & t); 

        /**
        * @brief Déplace la personne vers la droite si possible.
        * @param t Le terrain sur lequel la personne se déplace.
        * @return true si le déplacement a été effectué, false sinon.
        */
        bool moveRight(const Terrain & t); 

        /**
        * @brief Déplace la personne vers le haut si possible.
        * @param t Le terrain sur lequel la personne se déplace.
        * @return true si le déplacement a été effectué, false sinon.
        */
        bool moveUp(const Terrain & t); 

        /**
        * @brief Déplace la personne vers le bas si possible.
        * @param t Le terrain sur lequel la personne se déplace.
        * @return true si le déplacement a été effectué, false sinon.
        */
        bool moveDown(const Terrain & t); 
};

#endif