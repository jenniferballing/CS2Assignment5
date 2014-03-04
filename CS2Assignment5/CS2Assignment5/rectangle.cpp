#include "rectangle.h"

rectangle::rectangle(void)
{
    Length=0;
    Width=0;
    Type="Rectangle";
}
rectangle::rectangle(char* n, double l, double w):Geometry(n, "Rectangle")
{
    Type="Rectangle";
    Length=l;
    Width=w;
}
rectangle::rectangle(double l, double w)
{
    Type="Rectangle";
    Length=l;
    Width=w;
}
double rectangle::ComputeVolume()
{
    return 0;
}
double rectangle::ComputeSurface()
{
    return Length*Width;
}

rectangle::~rectangle(void)
{
    delete this;
}
