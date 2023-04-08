#ifndef _Terrain_H
#define _Terrain_H

class Terrain {
private:

    enum TypeCase { GRASS='.',WALL='#',DOOR='D',ST='A'};
    TypeCase tab_terr[28][15];

    unsigned short int dimx,dimy; // A réutiliser pour le mode texte.

public :
    /*Constructeurs, 1.Défaut dimx,dimy = 50 | 2. dimx = x, dimy = y | les terrains seront créés dans le tas car on aura plusieurs niveaux.*/
    Terrain();

    /*Destructeur, lors d'un changement de niveau cela permettra de delete le terrain qui n'est plus affiché*/
    ~Terrain();

    bool Collision(float x,float y) const ;

    TypeCase getXY(unsigned int x,unsigned  int y) const;

    unsigned  int getDimX();
    unsigned  int getDimY();


};
#endif