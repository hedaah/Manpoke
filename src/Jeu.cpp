#include "Jeu.h"

Jeu::Jeu(){

}


void Jeu::actionClavier(const char touche){
    switch (touche){
    case 'z':
            dres.moveUp();
            break;

    case 's':
            dres.moveDown();
            break;
    
    case 'd':
            dres.moveRight();
            break;
    
    case 'q':
            dres.moveLeft();
            break;

    default:
        break;
    }
}

void Jeu::actionsMonstre(){
    for(int i=0;i<=10;i++){
        tab[i].deplacerAuto();
    }
}

Terrain Jeu::getConstTerrain() const {return ter;}
 Dresseur Jeu::getConstDresseur() const {return dres;}