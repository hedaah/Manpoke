#include "Dresseur.h"
#include <iostream>

using namespace std;

Dresseur::Dresseur(){
    
    setPos(1,1);
    setVie(125);
    for(int i=0;i<=10;i++){

        //version 2 du stock pokeball //
        tab_StockPokeball[i].vec2_p.x=getPosX();
        tab_StockPokeball[i].vec2_p.y=getPosY()+0.8;
        tab_StockPokeball[i].m_Vie=-1;
        tab_StockPokeball[i].b_Lancement=true;

    }
    nb_RP=9;
    

}

int Dresseur::getPosXSP(){
    return tab_StockPokeball[nb_RP].vec2_p.x;
}

int Dresseur::getPosYSP(){
    return tab_StockPokeball[nb_RP].vec2_p.y;
}

int Dresseur::getPosXSPA(){
    return tab_StockPokeball[nb_RP+1].vec2_p.x;
}

int Dresseur::getPosYSPA(){
    return tab_StockPokeball[nb_RP+1].vec2_p.y;
}

int Dresseur::GetnombreRestantesPokemon(){
    return nb_RP;
}
void Dresseur::LienPokD2(){
    if(nb_RP>=0){
        tab_StockPokeball[nb_RP].vec2_p.x=getPosX();
        tab_StockPokeball[nb_RP].vec2_p.y=getPosY();
    }

}

void Dresseur::attaquer2(){
    for(int i=0;i<10;i++)
    {
        tab_StockPokeball[i].m_Degat=25;
    }
    switch (getDir())
    {
    case 0: //bas
        if(nb_RP>=0){
            /*while (StockPokeball[nb_RP].b_Lancement)
            {
                StockPokeball[nb_RP].vec2_p.y=StockPokeball[nb_RP].vec2_p.y+0.1;
                //
                cout<<"position du pokeball["<<nb_RP<< "]en y = "<<StockPokeball[nb_RP].vec2_p.x<<" et sa distance avec le dresseur est = "<<StockPokeball[nb_RP].vec2_p.distance2(StockPokeball[nb_RP].vec2_p,getVect2D())<<endl;
                if(StockPokeball[nb_RP].vec2_p.distance2(StockPokeball[nb_RP].vec2_p,getVect2D())>=200) StockPokeball[nb_RP].b_Lancement=false;

            }
            StockPokeball[nb_RP].vie=0;  
            nb_RP--;
            */

          if (tab_StockPokeball[nb_RP].b_Lancement){
            
                tab_StockPokeball[nb_RP].vec2_p.y=tab_StockPokeball[nb_RP].vec2_p.y+0.1;
                cout<<"position du pokeball["<<nb_RP<< "]en y = "<<tab_StockPokeball[nb_RP].vec2_p.x<<" et sa distance avec le dresseur est = "<<tab_StockPokeball[nb_RP].vec2_p.distance2(tab_StockPokeball[nb_RP].vec2_p,getVect2D())<<endl;
                }
                if(tab_StockPokeball[nb_RP].vec2_p.distance2(tab_StockPokeball[nb_RP].vec2_p,getVect2D())>=2){

                tab_StockPokeball[nb_RP].b_Lancement=false;

            
                tab_StockPokeball[nb_RP].m_Vie=0;  
                nb_RP--;
                }
            
        }
        break;

    case 1:
        if(nb_RP>=0){
            nb_RPA=nb_RP;
            while (tab_StockPokeball[nb_RP].b_Lancement)
            {
                tab_StockPokeball[nb_RP].vec2_p.y=tab_StockPokeball[nb_RP].vec2_p.y-0.1;
                cout<<"position du pokeball["<<nb_RP<< "]en y = "<<tab_StockPokeball[nb_RP].vec2_p.x<<" et sa distance avec le dresseur est = "<<tab_StockPokeball[nb_RP].vec2_p.distance2(tab_StockPokeball[nb_RP].vec2_p,getVect2D())<<endl;
                if(tab_StockPokeball[nb_RP].vec2_p.distance2(tab_StockPokeball[nb_RP].vec2_p,getVect2D())>=2) tab_StockPokeball[nb_RP].b_Lancement=false;

            }
            tab_StockPokeball[nb_RP].m_Vie=0;  
            nb_RP--;
        }
        break;

    case 2:
        if(nb_RP>=0){
            nb_RPA=nb_RP;
            while (tab_StockPokeball[nb_RP].b_Lancement)
            {
                tab_StockPokeball[nb_RP].vec2_p.x=tab_StockPokeball[nb_RP].vec2_p.x+0.1;
                cout<<"position du pokeball["<<nb_RP<< "]en x = "<<tab_StockPokeball[nb_RP].vec2_p.x<<" et sa distance avec le dresseur est = "<<tab_StockPokeball[nb_RP].vec2_p.distance2(tab_StockPokeball[nb_RP].vec2_p,getVect2D())<<endl;
                if(tab_StockPokeball[nb_RP].vec2_p.distance2(tab_StockPokeball[nb_RP].vec2_p,getVect2D())>=4) tab_StockPokeball[nb_RP].b_Lancement=false;

            }
            tab_StockPokeball[nb_RP].m_Vie=0;  
            nb_RP--;
        }
        break;

    case 3: 
        if(nb_RP>=0){
            while (tab_StockPokeball[nb_RP].b_Lancement)
            {
                tab_StockPokeball[nb_RP].vec2_p.x=tab_StockPokeball[nb_RP].vec2_p.x-0.1;
                cout<<"position du pokeball["<<nb_RP<< "]en x = "<<tab_StockPokeball[nb_RP].vec2_p.x<<" et sa distance avec le dresseur est = "<<tab_StockPokeball[nb_RP].vec2_p.distance2(tab_StockPokeball[nb_RP].vec2_p,getVect2D())<<endl;
                if(tab_StockPokeball[nb_RP].vec2_p.distance2(tab_StockPokeball[nb_RP].vec2_p,getVect2D())>=4) tab_StockPokeball[nb_RP].b_Lancement=false;

            }
            tab_StockPokeball[nb_RP].m_Vie=0;  
            nb_RP--;
        }
        break;

    default:
        break;
    }
}

unsigned short int Dresseur::getNbPokeball() {
    return m_nbPokeball;
}

void Dresseur::setNbPokeball(unsigned short int x) {
    if (x > 10) {
        cout << x << " le setter du nombre de pokeball a tenté de set un nombre de pokéball supérieur à 10, fonction échouée." << endl;
        return;
    }
    m_nbPokeball = x;
}

Pokeball* Dresseur::getTabPokeball(){
    return tab_StockPokeball;
}

Image* Dresseur::getTabImageVie(){
    return im_vie;
}
