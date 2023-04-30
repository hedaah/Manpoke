#ifndef _Dresseur_H
#define _Dresseur_H

#include "Vect2D.h"
#include "Personne.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

struct Pokeball {
    Vect2D vec2_p; // position
    int m_Vie; //sa vie
    int m_Degat; //son degat
    bool b_Lancement; // boolen pour gerer le lancement

    Image im_pokeball;

};


class Dresseur : public Personne{

    private :
        

        Pokeball tab_StockPokeball[10]; //stock Pokeball du Dresseur VERSION 2
        unsigned short int m_nbPokeball;
        int nb_RP; // nombre restantes de pokemon du Dresseur VERSION 2
        int nb_RPA;

        Image im_vie[6];

        


    public :

        Dresseur();// constructeur

        int getPosXSP(); //recupere la position x du pokeball[nb_RP]
        int getPosYSP(); //recupere la position x du pokeball[nb_RP]

        int getPosXSPA(); //recupere la position x du pokeball lancé 
        int getPosYSPA();  // recupere la position y du pokeball lancé

        unsigned short int getNbPokeball();
        void setNbPokeball(unsigned short int x);

        Pokeball* getTabPokeball();

        Image* getTabImageVie();

        int GetnombreRestantesPokemon();

        void LienPokD2();

        void attaquer2(); // generation des degats et lancements
        //Fin version 2//

        void capturemonstre(); // lancer des pokeballs

};

#endif