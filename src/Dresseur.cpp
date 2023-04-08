#include "Dresseur.h"
#include <iostream>

using namespace std;

Dresseur::Dresseur(){
    
    setPos(1,1);
    setVie(1000);
    for(int i=0;i<=10;i++){

        //version 2 du stock pokeball //
        StockPokeball[i].p.x=getPosX();
        StockPokeball[i].p.y=getPosY()+0.8;
        StockPokeball[i].vie=-1;
        StockPokeball[i].lancement=true;

    }

    nb_RP=9;
}
/* VERSION 1
void Dresseur::LienPokD(){
    for(int i=0;i<9;i++){
        pokeball[i].x=getPosX();
        pokeball[i].y=getPosY()+20;
    }
}

bool Dresseur::getBol(){
    return lancer;
}

void Dresseur::setBolF(){
    lancer=false;
}

void Dresseur::setBolT(){
    lancer=true;
}

Vect2D Dresseur::getPoke(int entier){
    return pokeball[entier];
}
int Dresseur::getPosXP(int entier){
    return pokeball[entier].x;
}

int Dresseur::getPosYP(int entier){
    return pokeball[entier].y;
}

void Dresseur::attaquer(int entier){
    switch (getDir())
    {
    case 0 : 
        //while(!lancer){ 
        pokeball[entier].y=pokeball[entier].y+0.10;
            //if(pokeball[entier].distance2(pokeball[entier],getVect2D())==200)
            //{
                //lancer=true;
            //}
       // }
        break;

    case 1 :
        pokeball[entier].y=pokeball[entier].y-0.10;
        break;

    case 2:
        pokeball[entier].x=pokeball[entier].x+0.10;
        break;

    case 3:
        pokeball[entier].x=pokeball[entier].x-0.10;
        break;

    
    default:
        break;
    }
}

*/

// VERSION 2//

int Dresseur::getPosXSP(){
    return StockPokeball[nb_RP].p.x;
}

int Dresseur::getPosYSP(){
    return StockPokeball[nb_RP].p.y;
}

int Dresseur::getPosXSPA(){
    return StockPokeball[nb_RP+1].p.x;
}

int Dresseur::getPosYSPA(){
    return StockPokeball[nb_RP+1].p.y;
}

int Dresseur::GetnombreRestantesPokemon(){
    return nb_RP;
}
void Dresseur::LienPokD2(){
    if(nb_RP>=0){
        StockPokeball[nb_RP].p.x=getPosX();
        StockPokeball[nb_RP].p.y=getPosY();
    }

}

void Dresseur::attaquer2(){
    for(int i=0;i<10;i++)
    {
        StockPokeball[i].degat=25;
    }
    switch (getDir())
    {
    case 0: //bas
        if(nb_RP>=0){
            /*while (StockPokeball[nb_RP].lancement)
            {
                StockPokeball[nb_RP].p.y=StockPokeball[nb_RP].p.y+0.1;
                //
                cout<<"position du pokeball["<<nb_RP<< "]en y = "<<StockPokeball[nb_RP].p.x<<" et sa distance avec le dresseur est = "<<StockPokeball[nb_RP].p.distance2(StockPokeball[nb_RP].p,getVect2D())<<endl;
                if(StockPokeball[nb_RP].p.distance2(StockPokeball[nb_RP].p,getVect2D())>=200) StockPokeball[nb_RP].lancement=false;

            }
            StockPokeball[nb_RP].vie=0;  
            nb_RP--;
            */

          if (StockPokeball[nb_RP].lancement){
            
                StockPokeball[nb_RP].p.y=StockPokeball[nb_RP].p.y+0.1;
                cout<<"position du pokeball["<<nb_RP<< "]en y = "<<StockPokeball[nb_RP].p.x<<" et sa distance avec le dresseur est = "<<StockPokeball[nb_RP].p.distance2(StockPokeball[nb_RP].p,getVect2D())<<endl;
                }
                if(StockPokeball[nb_RP].p.distance2(StockPokeball[nb_RP].p,getVect2D())>=2){

                StockPokeball[nb_RP].lancement=false;

            
                StockPokeball[nb_RP].vie=0;  
                nb_RP--;
                }
            
        }
        break;

    case 1:
        if(nb_RP>=0){
            nb_RPA=nb_RP;
            while (StockPokeball[nb_RP].lancement)
            {
                StockPokeball[nb_RP].p.y=StockPokeball[nb_RP].p.y-0.1;
                cout<<"position du pokeball["<<nb_RP<< "]en y = "<<StockPokeball[nb_RP].p.x<<" et sa distance avec le dresseur est = "<<StockPokeball[nb_RP].p.distance2(StockPokeball[nb_RP].p,getVect2D())<<endl;
                if(StockPokeball[nb_RP].p.distance2(StockPokeball[nb_RP].p,getVect2D())>=2) StockPokeball[nb_RP].lancement=false;

            }
            StockPokeball[nb_RP].vie=0;  
            nb_RP--;
        }
        break;

    case 2:
        if(nb_RP>=0){
            nb_RPA=nb_RP;
            while (StockPokeball[nb_RP].lancement)
            {
                StockPokeball[nb_RP].p.x=StockPokeball[nb_RP].p.x+0.1;
                cout<<"position du pokeball["<<nb_RP<< "]en x = "<<StockPokeball[nb_RP].p.x<<" et sa distance avec le dresseur est = "<<StockPokeball[nb_RP].p.distance2(StockPokeball[nb_RP].p,getVect2D())<<endl;
                if(StockPokeball[nb_RP].p.distance2(StockPokeball[nb_RP].p,getVect2D())>=4) StockPokeball[nb_RP].lancement=false;

            }
            StockPokeball[nb_RP].vie=0;  
            nb_RP--;
        }
        break;

    case 3: 
        if(nb_RP>=0){
            while (StockPokeball[nb_RP].lancement)
            {
                StockPokeball[nb_RP].p.x=StockPokeball[nb_RP].p.x-0.1;
                cout<<"position du pokeball["<<nb_RP<< "]en x = "<<StockPokeball[nb_RP].p.x<<" et sa distance avec le dresseur est = "<<StockPokeball[nb_RP].p.distance2(StockPokeball[nb_RP].p,getVect2D())<<endl;
                if(StockPokeball[nb_RP].p.distance2(StockPokeball[nb_RP].p,getVect2D())>=4) StockPokeball[nb_RP].lancement=false;

            }
            StockPokeball[nb_RP].vie=0;  
            nb_RP--;
        }
        break;

    default:
        break;
    }
}