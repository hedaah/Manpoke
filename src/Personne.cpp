#include "Personne.h"

Personne::Personne(){
    corps.x=0.0;
    corps.y=0.0;
    vie = 500;
}

void Personne::regeneration() {
    vie++;
}