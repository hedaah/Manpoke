#ifndef _Terrain_H
#define _Terrain_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "../sdl2/Image.h"



enum TypeCase { GRASS='.',WALL='#',DOOR='D',STONE='A',WATER='W'};

class Terrain {
private:

    TypeCase tab_terr[28][15];

    unsigned short int dimx,dimy; // A réutiliser pour le mode texte.

    Image im_wall;
    Image im_grass;
    Image im_door;
    Image im_stone;
    Image im_water;

public :
    /*Constructeurs, 1.Défaut dimx,dimy = 50 | 2. dimx = x, dimy = y | les terrains seront créés dans le tas car on aura plusieurs niveaux.*/
    Terrain();

    /*Destructeur, lors d'un changement de niveau cela permettra de delete le terrain qui n'est plus affiché*/
    ~Terrain();

    bool Collision(double& x,double& y) const ;

    TypeCase getXY(unsigned int x,unsigned  int y) const;

    Image& getImageTerrain(TypeCase c);
    void setImageTerrain(TypeCase c, const char* fileName, SDL_Renderer* renderer);

    void setMap(int j);

    unsigned  int getDimX();
    unsigned  int getDimY();


};

#endif