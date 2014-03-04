#define _USE_MATH_DEFINES
#include <cmath>
#include "Sphere.h"


Sphere::Sphere(void)
{
    Radius=0;
    Type="Sphere";
}
Sphere::Sphere(double r, char* n):Circle(r, n)
{
    Type="Sphere";
}
double Sphere::ComputeVolume()
{
    double frac= 4.0/3.0;
    double volume=M_PI*(Radius*Radius*Radius)*frac;
    return volume;
}
double Sphere::ComputeSurface()
{
    return 4*M_PI*(Radius*Radius);
}
Sphere::~Sphere(void)
{
    delete this;
}
