#include "Dresseur.h"

Dresseur::Dresseur(){
    lancer=true;
    setPos(450,200);
    setVie(1000);
    for(int i=0;i<9;i++){
        pokeball[i].x=getPosX();
        pokeball[i].y=getPosY()+20;
    }
    v.x=0.5;
    v.y=0.5;
}

void Dresseur::LienPokD(){
    for(int i=0;i<9;i++){
        pokeball[i].x=getPosX();
        pokeball[i].y=getPosY()+20;
    }
}

bool Dresseur::getBol(){
    return lancer;
}

void Dresseur::setBolF(){
    lancer=false;
}

void Dresseur::setBolT(){
    lancer=true;
}

Vect2D Dresseur::getPoke(int entier){
    return pokeball[entier];
}
int Dresseur::getPosXP(int entier){
    return pokeball[entier].x;
}

int Dresseur::getPosYP(int entier){
    return pokeball[entier].y;
}

void Dresseur::attaquer(int entier){
    switch (getDir())
    {
    case 0 : 
        //while(!lancer){ 
        pokeball[entier].y=pokeball[entier].y+0.10;
            //if(pokeball[entier].distance2(pokeball[entier],getVect2D())==200)
            //{
                //lancer=true;
            //}
       // }
        break;

    case 1 :
        pokeball[entier].y=pokeball[entier].y-0.10;
        break;

    case 2:
        pokeball[entier].x=pokeball[entier].x+0.10;
        break;

    case 3:
        pokeball[entier].x=pokeball[entier].x-0.10;
        break;

    
    default:
        break;
    }
}