#include "Geometry.h"


Geometry::Geometry(void)
{
    Name=" ";
    Type=" ";
}
Geometry::Geometry(char* n)
{
    Name=n;
}
Geometry::Geometry(char* n, char* t)
{
    Name=n;
    Type=t;
}
Geometry::Geometry(const Geometry &obj)
{
    Name=obj.Name;
    Type=obj.Type;
}
Geometry Geometry::operator=(const Geometry &obj)
{
    Name=obj.Name;
    Type=obj.Type;

    return *this;
}
char* Geometry::getName()
{
    return Name;
}
char* Geometry::getType()
{
    return Type;
}
double Geometry::ComputeVolume()
{
    return 0;
}
double Geometry::ComputeSurface()
{
    return 0;
}
Geometry::~Geometry(void)
{
    //delete this;
}
