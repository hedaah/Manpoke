#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Dresseur.h"
#include "monstre.h"
#include "Personne.h"
#include "Terrain.h"
#include "Vect2D.h"
#include "../texte/WinTXT.h"

using namespace std;

int main(){
    srand(time(NULL));

    Terrain terrain;
    Dresseur dresseur;
    Monstre monstre1(rand()%terrain.getDimX(), rand()%terrain.getDimY());
    Monstre monstre2(rand()%terrain.getDimX(), rand()%terrain.getDimY());
    Monstre monstre3(rand()%terrain.getDimX(), rand()%terrain.getDimY());

    dresseur.setPos(static_cast<float>(terrain.getDimX()/2), static_cast<float>(terrain.getDimY()/2));

    WinTXT win( terrain.getDimX(), terrain.getDimY()); // une fenêtre de taille 20 x 10
    bool ok = true;
    do
    {
        win.draw(); // Affichage de la fenêtre sur la console
        char c = win.getCh(); // lit une touche (non bloquant), c=0 si aucune touche

        for(unsigned int i = 0; i <terrain.getDimX() ; i++)
        {
            for(unsigned int j=0; j<terrain.getDimY() ; j++)
            {
                win.print(i,j,terrain.getXY(i,j));
            }
        }

        win.print(dresseur.getPosX(),dresseur.getPosY(),'P');
        win.print(monstre1.getPosX(),monstre1.getPosY(),'M');
        win.print(monstre2.getPosX(),monstre2.getPosY(),'M');
        win.print(monstre3.getPosX(),monstre3.getPosY(),'M');
         cout<<"oeoeoeo"<<endl;
        switch(c)
        {
            case 'z': // déplacement en haut
            {
                if (terrain.getXY(dresseur.getPosX(),dresseur.getPosY() - 1.0) == '#')
                {
                    break;
                }
                dresseur.moveUp();
                break;
            }
            case 'q':
            {
                if (terrain.getXY(dresseur.getPosX() - 1.0,dresseur.getPosY()) == '#')
                {
                    break;
                }
                dresseur.moveLeft();
                break;
            }
            case 's':
            {
                if (terrain.getXY(dresseur.getPosX(),dresseur.getPosY() + 1.0) == '#')
                {
                    break;
                }
                dresseur.moveDown();
                break;
            }
            case 'd':
            {
                if (terrain.getXY(dresseur.getPosX() + 1.0,dresseur.getPosY()) == '#')
                {
                    break;
                }
                dresseur.moveRight();
                break;
            }

            case 'l':
            {
                ok = false;
                break;
            }

        }
    } while(ok);

    return 0;
}