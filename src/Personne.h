#ifndef _Personne_H
#define _Personne_H

#include "Vect2D.h"

class Personne {
   
    
    public :
        Vect2D corps;
        int vie;
        
        Personne (); // constructeur 
        void regeneration ();// vie regeneré 

};

#endif