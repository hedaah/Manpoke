#include "Dresseur.h"

Dresseur::Dresseur(){
    setPos(0.0,0.0);
    setVie(1000);
    for(int i=0;i<9;i++){
        pokbeall[i].x=0.0;
        pokbeall[i].y=0.0; 
    }
    v.x=0.5;
    v.y=0.5;
}
