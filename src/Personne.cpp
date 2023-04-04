#include "Personne.h"

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

int Personne::getPosX() {
     return m_corps.x;
}

int Personne::getPosY() {
    return m_corps.y;
}

void Personne::setPos(float x, float y) {
    m_corps.x = x;
    m_corps.y = y;
}

Direction Personne::getDir() {
    return m_dir;
}

void Personne::setDir(Direction dir) {
    m_dir = dir;
}

void Personne::moveLeft(){
    setPos(getPosX() + 1.0, getPosY());
    m_dir = bas;
}

void Personne::moveRight(){
    setPos(getPosX() - 1.0, getPosY());
    m_dir = droite;
}

void Personne::moveUp(){
    setPos(getPosX(), getPosY() + 1.0);
    m_dir = haut;
}

void Personne::moveDown(){
    setPos(getPosX(), getPosY() - 1.0);
    m_dir = bas;  
}