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

void Personne::WORLVie(int x){
    m_vie= m_vie - x;
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
    cout << "coordonnée dresseur x : " << getPosX()  << " coordonnée dresseur y : " << getPosY() << endl; 

    cout<<t.Collision(getPosX()-1.0,getPosY())<<endl;
    if(t.Collision(getPosX(),getPosY())){
        
        setPos(getPosX() - (long double)0.05, getPosY());
    }
    
    //setPos(getPosX() + 0.1, getPosY());
}

void Personne::moveRight(const Terrain & t){
    cout<<"boolen vrai est "<<true<<endl;
    cout << "coordonnée dresseur x : " << getPosX() << " coordonnée dresseur y : " << getPosY() << endl; 

    cout<<t.Collision(m_corps.x+1.0,m_corps.y)<<endl;
    if(t.Collision(getPosX()+1.0,getPosY())){
        setPos(getPosX() + (long double)0.05, getPosY());
    }
    ////setPos(getPosX() - 0.1, getPosY());
}

void Personne::moveUp(const Terrain & t){
    cout<<"boolen vrai est "<<true<<endl;
    cout << "coordonnée dresseur x : " << getPosX() << " coordonnée dresseur y : " << getPosY() << endl; 
    cout<<t.Collision(getPosX(),getPosY())<<endl;
    if(t.Collision(getPosX(),getPosY()-1.0)){
        setPos(getPosX(), getPosY() - (long double)0.05);
    }
    //setPos(getPosX(), getPosY() + 0.1);
}

void Personne::moveDown(const Terrain & t){
    cout<<"boolen vrai est "<<true<<endl;
    cout << "coordonnée dresseur x : " << getPosX() << " coordonnée dresseur y : " << getPosY() << endl; 

    cout<<t.Collision(m_corps.x,m_corps.y)<<endl;
    if(t.Collision(getPosX(),getPosY()+1.0)){
        setPos(getPosX(), getPosY() + (long double)0.05); 
    }
    //setPos(getPosX(), getPosY() - 0.1);
}

Image& Personne::getImageSprite(){
    return im_sprites;
}

void Personne::getMovingState(bool& isMoving, unsigned short int& internalMovingState)
{
    isMoving = b_isMoving;
    internalMovingState = m_internalMovingState;
}

void Personne::setMovingState(const bool& isMoving, const unsigned short int& internalMovingState)
{
    b_isMoving = isMoving;
    m_internalMovingState = internalMovingState;
}

unsigned short int Personne::getInternalMovingState()
{
    return m_internalMovingState;
}

SDL_Rect* Personne::getTabSpritesRect(Direction dir)
{
    return rect_spritesPart[dir];
}