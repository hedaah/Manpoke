#include "Personne.h"
#include <iostream>
using namespace std;


Personne::Personne(){
    m_corps.x=1.0;
    m_corps.y=1.0;
    m_vie = 0;
    m_dir = bas;

    //Les sprites utilisés ont tous la même structure dans leur fichier png associé.

    getTabSpritesRect(haut)[0] = {0,192,64,64};
    getTabSpritesRect(haut)[1] = {64,192,64,64};
    getTabSpritesRect(haut)[2] = {128,192,64,64};
    getTabSpritesRect(haut)[3] = {192,192,64,64};

    getTabSpritesRect(bas)[0] = {0,0,64,64};
    getTabSpritesRect(bas)[1] = {64,0,64,64};
    getTabSpritesRect(bas)[2] = {128,0,64,64};
    getTabSpritesRect(bas)[3] = {192,0,64,64};

    getTabSpritesRect(gauche)[0] = {0,64,64,64};
    getTabSpritesRect(gauche)[1] = {64,64,64,64};
    getTabSpritesRect(gauche)[2] = {128,64,64,64};
    getTabSpritesRect(gauche)[3] = {192,64,64,64};

    getTabSpritesRect(droite)[0] = {0,128,64,64};
    getTabSpritesRect(droite)[1] = {64,128,64,64};
    getTabSpritesRect(droite)[2] = {128,128,64,64};
    getTabSpritesRect(droite)[3] = {192,128,64,64};
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
    m_vie= m_vie + x;
}

double Personne::getPosX() {
     return m_corps.x;
}

double Personne::getPosY() {
    return m_corps.y;
}

void Personne::setPos(double x, double y) {
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

bool Personne::moveLeft(const Terrain & t){
    bool moving;
    unsigned short int movingState;
    getMovingState(moving,movingState);
    if (movingState > 0)
    {
        setPos(getPosX() - (long double)0.05, getPosY());
        return true;
    }
    setDir(gauche);
    //cout << "coordonnée dresseur x : " << getPosX()  << " coordonnée dresseur y : " << getPosY() << endl; 
    double tmpx = getPosX() - 1.0;
    double tmpy = getPosY();

    //cout<<t.Collision(getPosX()-1.0,getPosY())<<endl;
    if(t.Collision(tmpx,tmpy)){
        
        setPos(getPosX() - (long double)0.05, getPosY());
        return true;
    }
    else
    {
        moving = false;
        movingState = 0;
        setMovingState(moving,movingState);
        return false;
    }
    
    //setPos(getPosX() + 0.1, getPosY());
}

bool Personne::moveRight(const Terrain & t){
    bool moving;
    unsigned short int movingState;
    getMovingState(moving,movingState);
    if (movingState > 0 )
    {
        setPos(getPosX() + (long double)0.05, getPosY());
        return true;
    }
    setDir(droite);
    //cout << "coordonnée dresseur x : " << getPosX() << " coordonnée dresseur y : " << getPosY() << endl; 
    double tmpx = getPosX() + 1.0;
    double tmpy = getPosY();

    //cout<<t.Collision(m_corps.x+1.0,m_corps.y)<<endl;
    if(t.Collision(tmpx,tmpy)){
        setPos(getPosX() + (long double)0.05, getPosY());
        return true;
    }
    else
    {
        moving = false;
        movingState = 0;
        setMovingState(moving,movingState);
        return false;
    }
    ////setPos(getPosX() - 0.1, getPosY());
}

bool Personne::moveUp(const Terrain & t){
    bool moving;
    unsigned short int movingState;
    getMovingState(moving,movingState);
    if (movingState > 0 )
    {
        setPos(getPosX(), getPosY() - (long double)0.05);
        return true;
    }
    setDir(haut);
    //cout << "coordonnée dresseur x : " << getPosX() << " coordonnée dresseur y : " << getPosY() << endl; 
    double tmpx = getPosX();
    double tmpy = getPosY() - 1.0;

    //cout<<t.Collision(getPosX(),getPosY())<<endl;
    if(t.Collision(tmpx,tmpy)){
        setPos(getPosX(), getPosY() - (long double)0.05);
        return true;
    }
    else
    {
        moving = false;
        movingState = 0;
        setMovingState(moving,movingState);
        return false;
    }
    //setPos(getPosX(), getPosY() + 0.1);
}

bool Personne::moveDown(const Terrain & t){
    bool moving;
    unsigned short int movingState;
    getMovingState(moving,movingState);
    //cout << "Movingstate : " << movingState << endl;
    if (movingState > 0)
    {
        setPos(getPosX(), getPosY() + (long double)0.05);
        return true;
    }

    setDir(bas);
    //cout << "coordonnée dresseur x : " << getPosX() << " coordonnée dresseur y : " << getPosY() << endl; 
    double tmpx = getPosX();
    double tmpy = getPosY() + 1.0;

    //cout<<t.Collision(m_corps.x,m_corps.y)<<endl;
    if(t.Collision(tmpx,tmpy)){
        setPos(getPosX(), getPosY() + (long double)0.05); 
        return true;
    }
    else
    {
        moving = false;
        movingState = 0;
        setMovingState(moving,movingState);
        return false;
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

SDL_Rect& Personne::getRectPos()
{
    return rect_spritePos;
}