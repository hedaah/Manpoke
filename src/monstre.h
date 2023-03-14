#include "Personne.h"
#ifndef MONSTER_H
#define MONSTER_H

enum TypeMonstre {
    petit,
    moyen,
    grand,
    boss

};

class Monstre: public Personne
{
  private :

  TypeMonstre m_type;

  public :
  
  float getX(); //retourne la position X 

  float getY(); //retourne la positionn en Y

  void deplacerAuto(); // deplacement aléatoire des monstres



};


#endif