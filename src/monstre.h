#ifndef MONSTER_H
#define MONSTER_H

#include "Personne.h"

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

  Monstre();
  Monstre(unsigned short int x, unsigned short int y); // m_type = moyen, vie = 100;
  Monstre(unsigned short int x, unsigned short int y, TypeMonstre type);

  void deplacerAuto(); // deplacement aléatoire des monstres



};


#endif