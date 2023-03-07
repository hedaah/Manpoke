#ifndef _COMPLEX_H
#define _COMPLEX_H


class Complex {

public:

    float x; // position x du complexe
    float y; // position y du complexe 

    Complex ();// constructeur par défaut

    Complex (const Complex & c); // Constructeur par défaut

    Complex make_complex(float r, float i); // Creation d'un complexe avec deux parametre

    Complex operator+ (Complex a); // additioner de complexe 

    Complex operator- (Complex a); // soustraction de complexe

    Complex operator* (Complex a); // multiplication de complexe

    Complex translate(Complex p, float dx,float dy); //

    int distance2 (Complex c1,Complex c2); // la distance entre deux complexe

};

#endif