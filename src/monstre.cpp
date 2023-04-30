#include <iostream>
#include "monstre.h"

Monstre::Monstre(){
    setPos(5,5);
    m_type = moyen;
    setVie(100);
}

Monstre::Monstre(unsigned short int x, unsigned short int y) {
    setPos((float)x,(float)y);
    m_type = moyen;
    setVie(100);
}

Monstre::Monstre(unsigned short int x, unsigned short int y, TypeMonstre type) {
    setPos((float)x,(float)y);
    m_type = type;
    switch(m_type) {
        case petit:
        {
            setVie(50);
            break;
        }
        case moyen:
        {
            setVie(100);
            break;
        }
        case grand:
        {
            setVie(200);
            break;
        }
        case boss:
        {
            setVie(1000);
            break;
        }
        default : 
            break;
    }
}

void Monstre::deplacerAuto(int tmp){
    Direction randDir;

    bool moving;
    unsigned short int movingstate;
    getMovingState(moving,movingstate);
    if (moving == true) // Si le monstre est déjà en mouvement on return
    {
        return;
    }

    switch (tmp)
    {
    case 0:
    {
       randDir = haut;
       setDir(randDir);
       moving = true;
       movingstate = 0;
       setMovingState(moving,movingstate);
       break; 
    }
    case 1:
    {
       randDir = bas;
       setDir(randDir);
       moving = true;
       movingstate = 0;
       setMovingState(moving,movingstate);
       break; 
    }
    case 2:
    {
       randDir = gauche;
       setDir(randDir);
       moving = true;
       movingstate = 0;
       setMovingState(moving,movingstate);
       break; 
    }
    case 3:
    {
       randDir = droite;
       setDir(randDir);
       bool moving;
       unsigned short int movingstate;
       moving = true;
       movingstate = 0;
       setMovingState(moving,movingstate);
       break; 
    }
    default:
        break;
    }
}

void Monstre::cleanMonstre(Monstre* p){
    delete p;
}