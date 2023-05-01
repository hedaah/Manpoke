#include "Dresseur.h"
#include <iostream>

using namespace std;

Dresseur::Dresseur(){
    
    nb_RP=50; //Nombre de pokeballs
    setPos(1,1);
    setVie(125);
    for(int i=0;i<=nb_RP;i++){

        Pokeball *p = new Pokeball;
        p->vec2_p.x=getPosX();
        p->vec2_p.y=getPosY();
        tab_pokeball.push_back(p);

    }
    b_isAttacking = false;
    USInt_internalAttackingState = 0;
    Vect2D vec_pokeball;
    vec_pokeball.make_Vect2D(0,0);
}

double Dresseur::getPosXSP(){
    return tab_pokeball[nb_RP]->vec2_p.x;
}

double Dresseur::getPosYSP(){
    return tab_pokeball[nb_RP]->vec2_p.y;
}

int Dresseur::getPosXSPA(){
    return tab_pokeball[nb_RP+1]->vec2_p.x;
}

int Dresseur::getPosYSPA(){
    return tab_pokeball[nb_RP+1]->vec2_p.y;
}

int Dresseur::GetnombreRestantesPokemon(){
    return nb_RP;
}
void Dresseur::LienPokD2(){
    if(nb_RP>0){
        cout<<"fonction LienPokd2 en cours "<<endl;
        for(int i=0; i<10;i++){
            tab_pokeball[i]->vec2_p.x=getPosX();
            tab_pokeball[i]->vec2_p.y=getPosY();

        }
        cout<<"P de x="<<tab_pokeball[9]->vec2_p.x<<" P de y="<<tab_pokeball[9]->vec2_p.y<<endl;
    }
}

void Dresseur::attaquer2(){
    for(int i=0;i<10;i++)
    {
        tab_pokeball[i]->m_Degat=50;
    }
    switch (getDir())
    {
    case haut: //haut
        if(nb_RP>0){
                tab_pokeball[nb_RP]->vec2_p.y=tab_pokeball[nb_RP]->vec2_p.y-4;
                cout<<"position du pokeball["<<nb_RP<< "]en y = "<<tab_pokeball[nb_RP]->vec2_p.y<<" et sa distance avec le dresseur est = "<<tab_pokeball[nb_RP]->vec2_p.distance2(tab_pokeball[nb_RP]->vec2_p,getVect2D())<<endl;
                cout<<"nombre restante du pokeball avant jeter ="<<nb_RP<<endl;
                nb_RP--;
                //ab_pokeball.pop_back();
                cout<<"nombre restante du pokeball ="<<nb_RP<<endl;
                
                

        }
        else {
            cout<<"plus de pokeball"<<endl;

        }
        break;

    case bas: // bas
        if(nb_RP>0){
                tab_pokeball[nb_RP]->vec2_p.y=tab_pokeball[nb_RP]->vec2_p.y+4;
                cout<<"position du pokeball["<<nb_RP<< "]en y= "<<tab_pokeball[nb_RP]->vec2_p.y<<" et sa distance avec le dresseur est = "<<tab_pokeball[nb_RP]->vec2_p.distance2(tab_pokeball[nb_RP]->vec2_p,getVect2D())<<endl;
                cout<<"nombre restante du pokeball avant jeter ="<<nb_RP<<endl;
                nb_RP--;
                //tab_pokeball.pop_back();
                cout<<"nombre restante du pokeball ="<<nb_RP<<endl;
        }
        else {
            cout<<"plus de pokeball"<<endl;
        }
        break;

    case gauche:
        if(nb_RP>0){
                tab_pokeball[nb_RP]->vec2_p.x=tab_pokeball[nb_RP]->vec2_p.x-4;
                cout<<"position du pokeball["<<nb_RP<< "]en x = "<<tab_pokeball[nb_RP]->vec2_p.x<<" et sa distance avec le dresseur est = "<<tab_pokeball[nb_RP]->vec2_p.distance2(tab_pokeball[nb_RP]->vec2_p,getVect2D())<<endl;
                nb_RP--;
                //tab_pokeball.pop_back();
                cout<<"nombre restante du pokeball ="<<nb_RP<<endl;
        }
        else {
            cout<<"plus de pokeball"<<endl;

        }
        break;

    case droite: 
        if(nb_RP>0){
                tab_pokeball[nb_RP]->vec2_p.x=tab_pokeball[nb_RP]->vec2_p.x+4;
                cout<<"position du pokeball["<<nb_RP<< "]en x = "<<tab_pokeball[nb_RP]->vec2_p.x<<" et sa distance avec le dresseur est = "<<tab_pokeball[nb_RP]->vec2_p.distance2(tab_pokeball[nb_RP]->vec2_p,getVect2D())<<endl;
                nb_RP--;
                //tab_pokeball.pop_back();
                cout<<"nombre restante du pokeball ="<<nb_RP<<endl;
        }
        else {
            cout<<"plus de pokeball"<<endl;

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

vector<Pokeball*> Dresseur::getTabPokeball(){
    return tab_pokeball;
}

Image* Dresseur::getTabImageVie(){
    return im_vie;
}

Vect2D Dresseur::getPokeball(){
    return tab_pokeball[nb_RP]->vec2_p;
}

Vect2D Dresseur::getDresseur(){
    return getVect2D(); 
}

void Dresseur::getAttackingState(bool& attacking,unsigned short int& internalAttackingState,Vect2D& vec_monstre, Vect2D& vec_pokeball)
{
    attacking = b_isAttacking;
    internalAttackingState = USInt_internalAttackingState;
    vec_monstre = vec_attackedMonster;
    vec_pokeball = vec_currentPokeballAttack;
}
void Dresseur::setAttackingState(bool attacking, unsigned short int internalAttackingState,Vect2D& vec_monstre, Vect2D& vec_pokeball)
{
    b_isAttacking = attacking;
    USInt_internalAttackingState = internalAttackingState;
    vec_attackedMonster = vec_monstre;
    vec_currentPokeballAttack = vec_pokeball;
}