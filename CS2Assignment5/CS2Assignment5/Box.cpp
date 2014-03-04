#include "Box.h"


Box::Box(void)
{
    Type="Box";
    Length=0;
    Width=0;
    Height=0;
}
Box::Box(char* n, double l,double w, double h):rectangle(n, l, w)
{
    Type="Box";
    Height=h;
}
double Box::ComputeVolume()
{
    return Length*Width*Height;
}
double Box::ComputeSurface()
{
    double frontBack=(Length*Width)*2;
    double Sides=(Width*Height)*2;
    double upDown=(Length*Height)*2;
    return frontBack+Sides+upDown;
}

Box::~Box(void)
{
    delete this;
}
