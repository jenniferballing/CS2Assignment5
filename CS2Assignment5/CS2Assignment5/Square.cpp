#include "Square.h"

Square::Square(void)
{
    Type="Square";
}
Square::Square(char* n, double s):Geometry(n)
{
    Type="Square";
    Side=s;
}
Square::Square(double s)
{
    Type="Square";
    Side=s;
}
double Square::ComputeVolume()
{
    return 0;
}
double Square::ComputeSurface()
{
    double surface= Side*Side;
    return surface;
}

Square::~Square(void)
{
    delete this;
}
