
#ifndef _Vect2D_H
#define _Vect2D_H

#include <math.h>


/**
    * @brief  Module qui représente un vecteur à deux dimensions en utilisant des coordonnées cartésiennes.
*/ 
class Vect2D{

public:

    double x; // position x du Vect2D4e
    double y; // position y du Vect2De 

   /**
     * @brief Constructeur par défaut qui initialise les coordonnées x et y du vecteur à 0.
    */
    Vect2D();

    /**
     * @brief Constructeur de copie qui prend une référence constante à un objet Vect2D.
     * @param c Objet Vect2D à copier.
     */

    Vect2D (const Vect2D & c); 

    /**
     * @brief Crée un nouveau Vect2D avec les coordonnées spécifiées.
     * @param r Coordonnée x.
     * @param i Coordonnée y.
     * @return Nouveau Vect2D avec les coordonnées spécifiées.
     */
    Vect2D make_Vect2D(double r, double i); 

    /**
     * @brief Effectue l'addition de deux vecteurs et renvoie le résultat.
     * @param a Vecteur à ajouter.
     * @return Nouveau vecteur résultant de l'addition des deux vecteurs.
     */
    Vect2D operator+ (Vect2D a);

    /**
     * @brief Effectue la soustraction de deux vecteurs et renvoie le résultat.
     * @param a Vecteur à soustraire.
     * @return Nouveau vecteur résultant de la soustraction des deux vecteurs.
     */
    Vect2D operator- (Vect2D a);

    /**
     * @brief Effectue la multiplication de deux vecteurs et renvoie le résultat.
     * @param a Vecteur à multiplier.
     * @return Nouveau vecteur résultant de la multiplication des deux vecteurs.
     */
    Vect2D operator* (Vect2D a); 

    /**
     * @brief Déplace le vecteur de la quantité spécifiée et renvoie le résultat.
     * @param p Vecteur à déplacer.
     * @param dx Déplacement sur l'axe x.
     * @param dy Déplacement sur l'axe y.
     * @return Nouveau vecteur résultant du déplacement.
     */
    Vect2D translate(Vect2D p, double dx,double dy); 

    /**
     * @brief Calcule la distance entre deux vecteurs au carré.
     * @param c1 Premier vecteur.
     * @param c2 Second vecteur.
     * @return Distance entre les deux vecteurs au carré.
     */
    int distance2 (Vect2D c1,Vect2D c2); // la distance entre deux Vect2D4e

};

#endif