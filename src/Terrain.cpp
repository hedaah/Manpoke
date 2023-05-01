#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>
#include <string.h>
#include <math.h>
#include "Terrain.h"


const char terrain1[15][28] = {

"###########################",

"#.......##................#",

"##D###..##......AA#######A#",

"#.......##......AA........#",

"#..#######..AAAAAA........#",

"#..##.......AAAAAA........#",

"#......#...##...AA........#",

"#####..#....#...AA........#",

"#......#....#...AA........#",

"#......#....#...AA...AA...#",

"#...........AAAAAAAAAAA...#",

"#....................AA...#",

"#.....#......#.......AA...#",

"#.....#......#.......AA...#",

"###########################"

};



const char terrain2[15][28] = {

"###########################",

"#.......##.......AA.......#",

"#.......##.......AA.......#",

"#####...##.......AA.......#",

"#.........................#",

"#####...........AA........#",

"#.........##....AA........#",

"#...............AA....#####",

"#...............AA........#",

"#..AAAAAAAA.....AA........#",

"#..AAAAAAAA..........AA...#",

"#####.#..AA..........AA...#",

"#..D#.#..AA..........AA...#",

"#.....#..AA..#.......AA...#",

"###########################"

};





const char terrain3[15][28] = {

"###########################",

"#.......##................#",

"#####...##......AA#########",

"#.......##......AAAA......#",

"#...............AAAA......#",

"#######.........AAAA..#####",

"#.........##....AAAA......#",

"########........AAAA..#####",

"#...............AAAA......#",

"#...............AAAA......#",

"#..#######...#..AAAA......#",

"#.....D......#..AAAA......#",

"#..AAAAAA....#..AAAA......#",

"#.....#......#............#",

"###########################",

};



const char terrain4[15][28] = {

"###########################",

"#.......##................#",

"#####...##.........########",

"#.......##................#",

"#.......##....AAA.........#",

"######........AAA.........#",

"#.........##..AAA.........#",

"########..##..AAA.....#####",

"#......#..##..AAA.........#",

"#.....D#..##..AAA.........#",

"#...####......AAA....AA...#",

"#......AAAAAAAAAA....AA...#",

"#......AAAAAAAAAA....AA...#",

"#.....#......#............#",

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

                case 'D' : tab_terr[i][j]=DOOR;
                        break;

                case 'A': tab_terr[i][j]=STONE;
                        break;
            }
        }
    }
    
}

void Terrain::setMap(int j){

   switch(j){
    case 0:
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

                case 'D' : tab_terr[i][j]=DOOR;
                        break;

                case 'A': tab_terr[i][j]=STONE;
                        break;
            }
        }
    }
     break;
    case 1:
         for(unsigned int i = 0; i< dimx ;++i)
    {
        for(unsigned int j = 0; j < dimy; ++j)
        {
            switch(terrain2[dimy-1-j][i])
            {
                case '#' : tab_terr[i][j]=WALL;
                        break;

                case '.' : tab_terr[i][j]=GRASS;
                        break;

                case 'D' : tab_terr[i][j]=DOOR;
                        break;

                case 'A': tab_terr[i][j]=STONE;
                        break;
            }
        }
    }
        break;

    case 2:
         for(unsigned int i = 0; i< dimx ;++i)
    {
        for(unsigned int j = 0; j < dimy; ++j)
        {
            switch(terrain3[dimy-1-j][i])
            {
                case '#' : tab_terr[i][j]=WALL;
                        break;

                case '.' : tab_terr[i][j]=GRASS;
                        break;

                case 'D' : tab_terr[i][j]=DOOR;
                        break;

                case 'A': tab_terr[i][j]=STONE;
                        break;
            }
        }
    }
    break;

    case 3:
         for(unsigned int i = 0; i< dimx ;++i)
    {
        for(unsigned int j = 0; j < dimy; ++j)
        {
            switch(terrain3[dimy-1-j][i])
            {
                case '#' : tab_terr[i][j]=WALL;
                        break;

                case '.' : tab_terr[i][j]=GRASS;
                        break;

                case 'D' : tab_terr[i][j]=DOOR;
                        break;

                case 'A': tab_terr[i][j]=STONE;
                        break;
            }
        }
    }
    break;
    
    default:
        break;
    }
 }


Terrain::~Terrain() {
    dimx=0;
    dimy=0;
}

bool Terrain::Collision(double& x,double& y)const {
   // std::cout << "AVant cast x : " << x << " avant cast y : " << y << std::endl;
    x = round(x);
    y = round(y);
    int x_int = static_cast<int>(x);
    int y_int = static_cast<int>(y);
    //std::cout << "x_int : " << x_int << " y_int " << y_int << std::endl;
    return ((x_int >= 0) && (x_int < dimx) && (y_int >= 0) && (y_int < dimy) && (tab_terr[x_int][y_int] != '#'));
    //return true; // SI BESOIN DE DEBUG DEPLACEMENT
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
        case DOOR:
        {
            return im_door;
            break;
        }
        case STONE:
        {
            return im_stone;
            break;
        }
        case WATER:
        {
            return im_water;
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
        case DOOR:
        {
            im_door.loadFromFile(fileName,renderer);
            break;
        }
        case STONE:
        {
            im_stone.loadFromFile(fileName,renderer);
            break;
        }
        case WATER:
        {
            im_water.loadFromFile(fileName,renderer);
            break;
        }
        default : break;
    }
}