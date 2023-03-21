#ifndef _Terrain_H
#define _Terrain_H

constexpr unsigned short int MAXTAB = 100;

class Terrain {

    unsigned short int dimx,dimy; // A réutiliser pour le mode texte.
    char tab_ter[MAXTAB][MAXTAB]; // Pour le mode texte, cela permet de créer plusieurs fenêtres représentant plusieurs niveaux.

public :
    /*Constructeurs, 1.Défaut dimx,dimy = 50 | 2. dimx = x, dimy = y | les terrains seront créés dans le tas car on aura plusieurs niveaux.*/
    Terrain();
    Terrain(unsigned short int x, unsigned short int y);

    /*Destructeur, lors d'un changement de niveau cela permettra de delete le terrain qui n'est plus affiché*/
    ~Terrain();

    /*Est-ce que les coordonnées représentent une case "collision" ?*/
    bool Collision(unsigned short int x,unsigned short int y);

    /*Pour le mode texte, on récupère le caractère des coordonnées passées en paramètres afin de déterminer si c'est une case "collision"*/
    char getXY(unsigned short int x,unsigned short int y);

    unsigned short int getDimX();
    unsigned short int getDimY();


};
#endif