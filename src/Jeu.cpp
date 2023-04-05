#include <iostream>

#include "Jeu.h"
using namespace std;

Jeu::Jeu(){

}


void Jeu::actionClavier(const char touche){
    switch (touche){
    case 'z':
            dres.moveUp();
            dres.LienPokD();
            break;

    case 's':
            dres.moveDown();
            dres.LienPokD();
            break;
    
    case 'd':
            dres.moveRight();
            dres.LienPokD();
            break;
    
    case 'q':
            dres.moveLeft();
            dres.LienPokD();
            break;
    case 'a':
        //     while(dres.getBol()){
            dres.attaquer(0);
            //cout<<"position du pokemon ="<<dres.getPoke(0).y<<endl;
            cout<<"la distance entre le pokemon et dresseur est ="<<dres.getPoke(0).distance2(dres.getPoke(0),dres.getVect2D())<<endl;
            if(dres.getPoke(0).distance2(dres.getPoke(0),dres.getVect2D())==200){
                        dres.setBolF();
                        cout<<"la valeur boolen "<<dres.getBol()<<endl;
                }
            if(dres.getPoke(0).distance2(dres.getPoke(0),dres.getVect2D())==201){
                        dres.setBolF();
                        cout<<"la valeur boolen "<<dres.getBol()<<endl;
                }
        //     }
        
            /*
            if(dres.getPoke(0).distance2(dres.getPoke(0),dres.getVect2D())==201){
                        dres.setBolF();
                        cout<<dres.getBol()<<endl;
                }
        */
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