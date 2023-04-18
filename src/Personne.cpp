#include "Personne.h"
#include <iostream>
using namespace std;


Personne::Personne(){
    m_corps.x=0.0;
    m_corps.y=0.0;
    m_vie = 0;
    m_dir = bas;
}


void Personne::regeneration() {
    m_vie++;
}

int Personne::getVie() {
    return m_vie;
}

void Personne::setVie(int x) {
    m_vie = x;
}

float Personne::getPosX() {
     return m_corps.x;
}

float Personne::getPosY() {
    return m_corps.y;
}

void Personne::setPos(float x, float y) {
    m_corps.x = x;
    m_corps.y = y;
}
Vect2D Personne::getVect2D(){
    return m_corps;
}
Direction Personne::getDir() {
    return m_dir;
}

void Personne::setDir(Direction dir) {
    m_dir = dir;

}

void Personne::moveLeft(const Terrain & t){
    cout<<"boolen vrai est "<<true<<endl;
    cout<<t.Collision(m_corps.x,m_corps.y)<<endl;
    if(t.Collision(getPosX()+1.0,getPosY())){
        
        setPos(getPosX() + 0.1, getPosY());
        m_dir = gauche;
    }
    
    //setPos(getPosX() + 0.1, getPosY());
}

void Personne::moveRight(const Terrain & t){
    cout<<"boolen vrai est "<<true<<endl;
    cout<<t.Collision(m_corps.x,m_corps.y)<<endl;
    if(t.Collision(getPosX()-1.0,getPosY())){
        setPos(getPosX() - 0.1, getPosY());
        m_dir = droite;
    }
    ////setPos(getPosX() - 0.1, getPosY());
}

void Personne::moveUp(const Terrain & t){
    cout<<"boolen vrai est "<<true<<endl;
    cout<<t.Collision(m_corps.x,m_corps.y)<<endl;
    if(t.Collision(getPosX(),getPosY()+1)){
        setPos(getPosX(), getPosY() + 1.0);
        m_dir = haut;
    }
    //setPos(getPosX(), getPosY() + 0.1);
}

void Personne::moveDown(const Terrain & t){
    cout<<"boolen vrai est "<<true<<endl;
    cout<<t.Collision(m_corps.x,m_corps.y)<<endl;
    if(t.Collision(getPosX(),getPosY()-1)){
        setPos(getPosX(), getPosY() - 1);
        m_dir = bas;  
    }
    //setPos(getPosX(), getPosY() - 0.1);
}

Image* Personne::getImageSprite(){
    return &im_sprite[0];
}