#ifndef _COMPLEX_H
#define _COMPLEX_H

class Complex {

public:

    float x; // position x du complexe
    float y; // position y du complexe 

    Complex ();// constructeur par défaut

    Complex (const Complex & c); // Constructeur par défaut

    Complex make_complex(float r, float i); // Creation d'un complexe avec deux parametre



};

#endif