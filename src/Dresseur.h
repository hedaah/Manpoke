#ifndef _Dresseur_H
#define _Dresseur_H


#include <vector>

#include "Vect2D.h"
#include "Personne.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

struct Pokeball {
    Vect2D vec2_p; // position
    int m_Degat; //son degat
    bool b_Lancement; // boolen pour gerer le lancement

    Image im_pokeball;

};

/**

    @class Dresseur
    @brief Module  représentant un dresseur.
    Cette classe hérite de la classe Personne et permet de gérer les interactions entre un dresseur et ses pokémons.
    */
class Dresseur : public Personne{

    private :

        vector<Pokeball*> tab_pokeball;     //stock Pokeball du Dresseur VERSION 2
        unsigned short int m_nbPokeball;
        int nb_RP; // nombre restantes de pokemon du Dresseur VERSION 2
        int nb_RPA;

        Image im_vie[6];

        bool b_isAttacking;
        unsigned short int USInt_internalAttackingState;
        Vect2D vec_attackedMonster;
        Vect2D vec_currentPokeballAttack;

        


    public :

        /**
        * @brief Constructeur par défaut de la classe Dresseur.
        */  
        Dresseur();// constructeur

        /**
         * @brief Récupère la position x de la pokeball actuellement sélectionnée.
         * @return La position x de la pokeball.
         */
        double getPosXSP(); 

        /**
         * @brief Récupère la position y de la pokeball actuellement sélectionnée.
         * @return La position y de la pokeball.
        */
        double getPosYSP(); 
        
        /**
         * @brief Récupère la position x de la pokeball en cours de lancement.
         * @return La position x de la pokeball.
         */
        int getPosXSPA(); 

        /**
         * @brief Récupère la position yde la pokeball en cours de lancement.
         * @return La position y de la pokeball.
         */
        int getPosYSPA();  

        /**
         * @brief Récupère le nombre de pokeballs que possède le dresseur.
         * @return Le nombre de pokeballs.
         */
        unsigned short int getNbPokeball();

        /**
         * @brief Modifie le nombre de pokeballs que possède le dresseur.
         * @param x Le nouveau nombre de pokeballs.
         */
        void setNbPokeball(unsigned short int x);

        /**

        @brief Renvoie l'état d'attaque actuel du dresseur.
        @param attacking Référence vers un booléen qui sera mis à vrai si le dresseur est en train d'attaquer.
        @param internalAttackingState Référence vers un entier qui décrit l'étape de l'attaque en cours.
        @param vecMonstre Référence vers un Vect2D qui représente la position du monstre attaqué.
        @param vecPokeball Référence vers un Vect2D qui représente la position de la pokeball utilisée pour attaquer.
        */

        void getAttackingState(bool& attacking,unsigned short int& internalAttackingState,Vect2D& vecMonstre, Vect2D& vecPokebal);

        /**

        @brief Modifie l'état d'attaque actuel du dresseur.
        @param attacking Booléen qui décrit si le dresseur est en train d'attaquer.
        @param internalAttackingState Entier qui décrit l'étape de l'attaque en cours.
        @param vecMonstre Vect2D qui représente la position du monstre attaqué.
        @param vecPokeball Vect2D qui représente la position de la pokeball utilisée pour attaquer.
    */
        void setAttackingState(bool attacking, unsigned short int internalAttackingState, Vect2D& vecMonstre, Vect2D& vecPokeball);

        /**

        @brief Renvoie un vecteur contenant les pointeurs vers toutes les pokeballs possédées par le dresseur.
        @return Un vecteur de pointeurs vers des Pokeball.
        */

        vector<Pokeball*> getTabPokeball();

        /**

        @brief Renvoie un tableau d'Image contenant les images des différentes vies du dresseur.
        @return Un tableau d'Image.
        */

        Image* getTabImageVie();

        /**

        @brief Renvoie la position de la pokeball sélectionnée pour l'attaque en cours.
        @return Un Vect2D représentant la position de la pokeball.
        */

        Vect2D getPokeball();

        /**

        @brief Renvoie la position du dresseur.
        @return Un Vect2D représentant la position du dresseur.
        */

        Vect2D getDresseur();

        /**

        @brief Renvoie le nombre restant de Pokémon possédés par le dresseur.
        @return Le nombre restant de Pokémon.
        */

        int GetnombreRestantesPokemon();

        /**

        @brief Crée des liens entre les différentes pokeballs et les monstres de la région.
        */

        void LienPokD2();
        
        /**
        @brief Génère des dégâts et lance une pokeball pour attaquer le monstre le plus proche.
        */

        void attaquer2(); 
       

        

};

#endif