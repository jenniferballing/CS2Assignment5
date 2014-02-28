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
    double volume=(4/3)*M_PI*(Radius*Radius*Radius);
    return volume;
}
double Sphere::ComputeSurface()
{
    return 4*M_PI*(Radius*Radius);
}
Sphere::~Sphere(void)
{
}
