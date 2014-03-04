#define _USE_MATH_DEFINES
#include <cmath>
#include "Circle.h"

Circle::Circle(void)
{
    Radius=0;
    Type="Circle";
}
Circle::Circle(char* n, double r):Geometry(n)
{
    Type="Circle";
    Radius=r;
}
double Circle::getRadius()
{
    return Radius;
}
Circle::Circle(double r)
{
    Type="Circle";
    Radius=r;
}
double Circle::ComputeVolume()
{
    return 0;
}
double Circle::ComputeSurface()
{
    double surface=M_PI*(Radius*Radius);
    return surface;
}
Circle::~Circle(void)
{
    delete this;
}
