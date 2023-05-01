#ifndef _JEU_H
#define _JEU_H

#include <stdlib.h>
#include <time.h>
#include <sstream>

#include "Dresseur.h"
#include "Terrain.h"
#include "monstre.h"
#include "../sdl2/Image.h"
#include <vector>

using namespace std;

/**

    @class Jeu
    @brief Module représentant le jeu Manpoke
    La classe Jeu gère l'ensemble des éléments du jeu, tels que le terrain, les dresseurs,
    les monstres, le score et les points de vie. Elle s'occupe également de l'affichage
    du jeu grâce à la bibliothèque SDL2.
    */
class Jeu {

private :

	Terrain ter;
	Dresseur dres;
    vector<Monstre*> tab_monstres;

    SDL_Window * window;
    SDL_Renderer * renderer;


    TTF_Font * font;
    Image font_im;
    Image font_point;
    SDL_Color font_color;

    Mix_Chunk * sound;
    Mix_Chunk * pas;
    bool withSound;

    Image im_Menu[3];
    Image Im_score;
    Image Im_Pr;

    int niveau;

    int score;
    string score_str;

    int point;
    string point_str;
    

    unsigned short int USInt_level;
    unsigned short int USInt_nbMonstre;

public :

    /**
     * @brief Constructeur de la classe Jeu.
     */
    Jeu();

    /**
     * @brief Destructeur de la classe Jeu.
     */
    ~Jeu();



    /**
     * @brief Accesseur pour le terrain du jeu.
     * @return Une référence constante vers le terrain du jeu.
     */
    const Terrain& getConstTerrain () const;  

    
    /**
     * @brief Accesseur pour le nombre de monstres restants dans le jeu.
     * @return Le nombre de monstres restants dans le jeu.
     */                      
    const Dresseur& getConstDresseur () const; 

    /**
     * @brief Accesseur pour le nombre de monstres restants dans le jeu.
     * @return Le nombre de monstres restants dans le jeu.
     */                        
                                                                        
    int getNombreDeMonstre() const;  

    /**
     * @brief Actions des monstres du jeu.
     */                              

    void actionsMonstre ();

    /**
     * @brief Gestion des actions du joueur en fonction des touches du clavier.
     * @param touche La touche du clavier appuyée par le joueur.
     */
    void actionClavier(const char touche);          

    /**
     * @brief Gestion des actions du joueur en fonction des touches du clavier.
     * @param  p la personne utilise.
     */
    void gestionDeplacement(Personne& p);

    /**
     * @brief Gestion des rendu.
     * @param p la personne utilise..
     */
    void gestionRendue(Personne& p);

    /**
     * @brief Gestion des attaques du dresseur.
     * @param d le dresseur
     */


    void gestionAttaques(Dresseur& d);

    /**
     * @brief Gestion de changement de niveau.
     * @param i un entier de niveau
     */

    void changeLevel(int i);

    /**
     * @brief Setup des draws a jour
     * @param state entier du menu
     */
    
    void setupRenderer(int state);

    //Fonctions affichage SDL
    /**
     * @brief Iinitialise la fenetre sdl
     *
     */
    void afficherInit();

    /**
     * @brief Detruit la fenetre
     *
     */
    void afficherDetruit();

    /**
     * @brief retourne un Gameloop
     *
     */
    void afficherBoucle();

    /**
     * @brief Affiche la fenetre
     *
     */
    void afficher();

};

 


#endif
