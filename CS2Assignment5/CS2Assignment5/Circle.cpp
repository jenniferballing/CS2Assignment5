#define _USE_MATH_DEFINES
#include <cmath>
#include "Circle.h"

Circle::Circle(void)
{
    Radius=0;
    Type="Circle";
}
Circle::Circle(double r, char* n):Geometry(n)
{
    Type="Circle";
    Radius=r;
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
}
