#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>
#include <string.h>
#include "Terrain.h"

const char terrain1[15][28] = {
 "###########################",
 "#.......##................#",
 "##D###..##..........#######",
 "#.......##................#",
 "#..#######..AAAAAA........#",
 "#..##...........AA........#",
 "#......#...##...AA........#",
 "#####..#....#...AA....#####",
 "#......##...#...AA........#",
 "#......#....#...AA........#",
 "#...........AAAAAAAAAAA...#",
 "#....................AA...#",
 "#.....#......#.......AA...#",
 "#.....#......#.......AA...#",
 "###########################"
};


/**/

 

Terrain::Terrain() {
    dimx = 27;
    dimy = 15;
    for(unsigned int i = 0; i< dimx ;++i)
    {
        for(unsigned int j = 0; j < dimy; ++j)
        {
            switch(terrain1[dimy-1-j][i])
            {
                case '#' : tab_terr[i][j]=WALL;
                        break;

                case '.' : tab_terr[i][j]=GRASS;
                        break;

                case 'A': tab_terr[i][j]=STONE;
                        break;
            }
        }
    }
    
}


Terrain::~Terrain() {
    dimx=0;
    dimy=0;
}

bool Terrain::Collision(float x,float y)const {
    int x_int = static_cast<int>(x);
    int y_int = static_cast<int>(y);
    std::cout << "x_int : " << x_int << " y_int " << y_int << std::endl;
    return ((x_int >= 0) && (x_int < dimx) && (y_int >= 0) && (y_int < dimy) && (tab_terr[x_int][y_int] != '#'));
}

TypeCase Terrain::getXY(unsigned int x,unsigned  int y)const {
    assert(x>=0);
    assert(y>=0);
    assert(x<dimx);
    assert(y<dimy);
    return tab_terr[x][y];
}

unsigned int Terrain::getDimX(){
    return dimx;
}

unsigned  int Terrain::getDimY(){
    return dimy;
}

Image& Terrain::getImageTerrain(TypeCase c){
    //std::cout << "Texture de wall "<<im_wall.getTexture() << std::endl;
    switch(c)
    {
        case GRASS:
        {
            return im_grass;
            break;
        }
        case WALL:
        {
            return im_wall;
            break;
        }
        case STONE:
        {
            return im_stone;
            break;
        }
        default :
        {
            return im_grass;
            break;
        } 
    }
}

void Terrain::setImageTerrain(TypeCase c, const char* fileName, SDL_Renderer* renderer){
    switch(c)
    {
        case GRASS:
        {
            im_grass.loadFromFile(fileName,renderer);
            break;
        }
        case WALL:
        {
            im_wall.loadFromFile(fileName,renderer);
            break;
        }
        case STONE:
        {
            im_stone.loadFromFile(fileName,renderer);
            break;
        }
        default : break;
    }
}