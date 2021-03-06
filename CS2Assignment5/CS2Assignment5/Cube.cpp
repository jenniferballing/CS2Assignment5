#include "Cube.h"


Cube::Cube(void)
{
    Side=0;
    Type="Cube";
}

Cube::Cube(char*n, double s):Square(n, s)
{
    Type="Cube";
}
double Cube::getSide()
{
    return Side;
}
double Cube::ComputeVolume()
{
    double volume= Side*Side*Side;
    return volume;
}
double Cube::ComputeSurface()
{
    double surface=(Side*Side)*6;
    return surface;
}

Cube::~Cube(void)
{
    delete this;
}
