#include "Vect2D.h"

Vect2D::Vect2D()
{
    x=0.0;
    y=0.0;
}

Vect2D::Vect2D(const Vect2D & a)
{
    x=a.x;
    y=a.y;
}

Vect2D Vect2D::make_Vect2D(double r,double i)
{
    Vect2D c;
    c.x=r;
    c.y=i;
    return c;
}

Vect2D Vect2D::operator+ (Vect2D a){
    Vect2D c=make_Vect2D (x+a.x,y+a.y);
    return c;
}

Vect2D Vect2D::operator- (Vect2D a){
    Vect2D c=make_Vect2D(x-a.x,y-a.y);
    return c;
}

Vect2D  Vect2D::operator*(Vect2D a){
    Vect2D c=make_Vect2D(x*a.x,y*a.y);
    return c;
}

Vect2D Vect2D::translate(Vect2D p, double dx,double dy)
{
    return p+make_Vect2D(dx,dy);
}

int Vect2D::distance2(Vect2D c1,Vect2D c2)
{
    Vect2D c=c1-c2;
    return sqrt(c.x*c.x+c.y*c.y);

}