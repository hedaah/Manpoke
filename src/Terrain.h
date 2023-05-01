#ifndef _Terrain_H
#define _Terrain_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "../sdl2/Image.h"



enum TypeCase { GRASS='.',WALL='#',DOOR='D',STONE='A',WATER='W'};


/**

    @class Terrain
    @brief Module pour gérer les terrains du jeu.
    Cette classe permet de créer, afficher et gérer les différents terrains du jeu.
    Elle utilise des images pour afficher les différentes cases du terrain.
    */

class Terrain {
private:

    TypeCase tab_terr[28][15];

    unsigned short int dimx,dimy; // A réutiliser pour le mode texte.

    Image im_wall;
    Image im_grass;
    Image im_door;
    Image im_stone;
    Image im_water;

public :
    /**
    @brief Constructeur par défaut de la classe Terrain.
    Initialise un terrain par défaut de 28x15 cases.
    */
    Terrain();

    /**

    @brief Destructeur de la classe Terrain.
    Libère les ressources allouées pour les images.
    */
    ~Terrain();

    /**
    @brief Vérifie s'il y a une collision avec une case.
    Vérifie s'il y a une collision avec la case correspondant aux coordonnées passées en paramètres.
    @param x La coordonnée x du joueur.
    @param y La coordonnée y du joueur.
    @return True s'il y a collision, false sinon.
    */
    bool Collision(double& x,double& y) const ;

    /**

    @brief Récupère le type de case aux coordonnées passées en paramètres.
    @param x La coordonnée x de la case.
    @param y La coordonnée y de la case.
    @return Le type de case aux coordonnées passées en paramètres.
    */
    TypeCase getXY(unsigned int x,unsigned  int y) const;

    /**
    @brief Récupère l'image correspondant au type de case passé en paramètre.
    @param c Le type de case dont on veut récupérer l'image.
    @return L'image correspondant au type de case passé en paramètre.
    */
    Image& getImageTerrain(TypeCase c);

    /**
    @brief Définit l'image correspondant au type de case passé en paramètre.
    @param c Le type de case dont on veut définir l'image.
    @param fileName Le nom du fichier image à utiliser.
    @param renderer Le renderer SDL sur lequel dessiner l'image.
    */
    void setImageTerrain(TypeCase c, const char* fileName, SDL_Renderer* renderer);

    /**
    @brief Charge une carte à partir d'un fichier de carte.
    @param j Le numéro de la carte à charger.
    */
    void setMap(int j);

    /**
    @brief Récupère la dimension en x du terrain.
    @return La dimension en x du terrain.
    */
    unsigned  int getDimX();

    /**
    @brief Récupère la dimension en y du terrain.
    @return La dimension en x du terrain.
    */
    unsigned  int getDimY();


};

#endif