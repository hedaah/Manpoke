#include "Dresseur.h"

Dresseur::Dresseur(){
    dress.corps.x=350.0;
    dress.corps.y=500.0;
    for(int i=0;i<9;i++){
        pokbeall[i].x=0.0;
        pokbeall[i].y=0.0; 
    }
    v.x=0.5;
    v.y=0.5;
}

void Dresseur::DeplaGauche(){

    dress.corps.x=dress.corps.x-v.x;

}

void Dresseur::DeplaDroite(){
    dress.corps.x=dress.corps.x+v.x;
}

void Dresseur::DeplaHaut(){
    dress.corps.y=dress.corps.y+v.y;
}

void Dresseur::DeplaBas(){
    dress.corps.y=dress.corps.y-v.y;
}