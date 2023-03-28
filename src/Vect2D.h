#ifndef _Vect2D_H
#define _Vect2D_H

#include <math.h>


class Vect2D{

public:

    float x; // position x du Vect2D4e
    float y; // position y du Vect2De 

    Vect2D();// constructeur par défaut

    Vect2D (const Vect2D & c); // Constructeur par défaut

    Vect2D make_Vect2D(float r, float i); // Creation d'un Vect2De avec deux parametre

    Vect2D operator+ (Vect2D a); // additioner de Vect2De 

    Vect2D operator- (Vect2D a); // soustraction de Vect2De

    Vect2D operator* (Vect2D a); // multiplication de Vect2De

    Vect2D translate(Vect2D p, float dx,float dy); //

    int distance2 (Vect2D c1,Vect2D c2); // la distance entre deux Vect2D4e

};

#endif