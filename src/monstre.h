#ifndef MONSTER_H
#define MONSTER_H

#include "Personne.h"

enum TypeMonstre {
  petit,
  moyen,
  grand,
  boss
};

/**

    @class Monstre
    @brief Module représentant un monstre dans le jeu.
    Cette classe hérite de la classe Personne et permet de représenter un monstre dans le jeu.
    */
class Monstre: public Personne
{
  
  private :

  TypeMonstre m_type;

  public :

  /**

    @brief Constructeur par copie de la classe Monstre.
    @param type Le type de monstre.
  */
  Monstre(TypeMonstre type);

  /**

    @brief Constructeur par copie de la classe Monstre.
    @param x La coordonnée x du monstre.
    @param y La coordonnée y du monstre.
    Ce constructeur crée un monstre de type moyen avec une vie de 100 points.
  */
  Monstre(unsigned short int x, unsigned short int y);

  /**

    @brief Constructeur par copie de la classe Monstre.
    @param x La coordonnée x du monstre.
    @param y La coordonnée y du monstre.
    @param type Le type de monstre.
  */
  Monstre(unsigned short int x, unsigned short int y, TypeMonstre type);

  /**

    @brief Destructeur de la classe Monstre.
    Ce destructeur supprime le monstre.
    */

  void cleanMonstre(Monstre* p);

  /**

    @brief Getter pour le type du monstre.
    @return Le type du monstre.
  */
  TypeMonstre getType();

  /**

    @brief Déplace le monstre automatiquement.
    @param tmp Le temps écoulé depuis le dernier déplacement.
    Cette méthode permet de déplacer le monstre de manière aléatoire.
  */
  void deplacerAuto(int tmp); // deplacement aléatoire des monstres



};


#endif