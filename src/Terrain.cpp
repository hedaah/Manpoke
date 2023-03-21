#include <iostream>
#include "Terrain.h"
#include <stdlib.h>
#include <time.h>

Terrain::Terrain() {
    dimx = 50;
    dimy = 50;
    srand(time(NULL));
    for(unsigned int i = 0; i< dimx ; i++)
    {
        for(unsigned int j = 0; j < dimy; j++)
        {
            //std::cout << "Itération numéro : " << i << " " << j << " passée" << std::endl;
            tab_ter[i][j] = '.'; // Caractère par défaut du niveau, représentant une case sur laquelle les entités (Personnes) peuvent marcher.
        }
    }

    for(unsigned int i = 0; i < 5; i++)
    {
        tab_ter[(unsigned int)rand() % dimx][(unsigned int)rand() % dimy] = '#';
    }
}

Terrain::Terrain(unsigned short x, unsigned short y) {
    dimx = x;
    dimy = y;
    srand(time(NULL));
    for(unsigned int i = 0; i< dimx ; i++)
    {
        for(unsigned int j = 0; j < dimy; j++)
        {
            tab_ter[i][j] = '.'; // Caractère par défaut du niveau, représentant une case sur laquelle les entités (Personnes) peuvent marcher.
        }
    }

    for(unsigned int i = 0; i < 5; i++) // Pour le mode texte on génére un niveau aléatoire contenant seulement 5 obstacles.
    {
        tab_ter[(unsigned int)rand() % dimx][(unsigned int)rand() % dimy] = '#';
    }
}

Terrain::~Terrain() {
    dimx=0;
    dimy=0;
}

char Terrain::getXY(unsigned short int x,unsigned short int y){
    return tab_ter[x][y];
}

bool Terrain::Collision(unsigned short int x, unsigned short int y){
    return getXY(x,y) == '#';
}

unsigned short int Terrain::getDimX(){
    return dimx;
}

unsigned short int Terrain::getDimY(){
    return dimy;
}