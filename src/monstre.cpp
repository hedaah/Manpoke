#include <iostream>
#include "monstre.h"

Monstre::Monstre(){

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

void Monstre::deplacerAuto(){
    
}